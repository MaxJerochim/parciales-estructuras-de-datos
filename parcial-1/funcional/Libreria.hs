-- =====================================================================
--  Libreria.hs - Implementación del TAD Libreria
--  EJERCICIO 2: invariantes de representación (en el comentario de abajo).
--  EJERCICIO 3: implementar vender y masVendido.
--
--  Acá SÍ se usa la representación (Lib m s), porque es la implementación.
--  N = cantidad de libros registrados, D = cantidad con stock > 0.
-- =====================================================================

module Libreria
  ( Libreria, Codigo, Cantidad
  , nuevaLibreria, registrar, reponer, vender
  , stockDe, disponibles, masVendido
  ) where

import Map
import Set

type Codigo = String
type Cantidad = Int

data Libreria = Lib (Map Codigo (Int, Int))  -- (stock, ventas) por libro
                    (Set Codigo)             -- libros con stock > 0
  deriving Show

-- =====================================================================
--  EJERCICIO 2: Invariantes de representación
-- =====================================================================
{-
  Sea (Lib m s) una Libreria. Se cumple que:

  1. Todo código que es clave de m con stock mayor a 0 pertenece a s.

  2. Todo código que pertenece a s es clave de m, y su stock en m es
     mayor a 0.

  3. Para todo código de m, el stock y las ventas de su tupla son
     mayores o iguales a 0.
-}

-- =====================================================================
--  EJERCICIO 3
-- =====================================================================

-- Propósito: describe la librería que resulta de descontar una unidad del
--            stock del libro dado e incrementar en una unidad sus ventas.
-- Precondición: el libro está registrado y tiene stock mayor que cero.
-- Eficiencia: O(log N)  porque las operaciones assocM, looukpM y deleteS son de orden log n
vender :: Codigo -> Libreria -> Libreria
vender c (Lib m s) = case lookupM c m of
                          Nothing -> error "libro no registrado"
                          Just t  -> let t'    = tuplaModificada t
                                         stock = fst(t') 
                                     in if stock > 0
                                           then Lib (assocM c t' m) s
                                           else Lib (assocM c t' m) (deleteS c s)

tuplaModificada :: (Int, Int) -> (Int, Int)
tuplaModificada t = (fst(t) - 1, snd(t) + 1)

-- Propósito: describe el código del libro con más ventas acumuladas;
--            en caso de empate, cualquiera de los que tengan más ventas.
-- Precondición: al menos un libro tiene ventas mayores a cero.
-- Eficiencia: O(N log N), siendo N la cantidad de libros registrados.
--             keysM es O(N), y la subtarea recorre los N códigos
--             haciendo en cada uno 2 lookupM de O(log N)
masVendido :: Libreria -> Codigo
masVendido (Lib m _) = let claves = keysM m
                       in masVendido' claves m

masVendido' :: [Codigo] -> (Map Codigo (Int, Int)) -> Codigo
masVendido' []     m = error "hay al menos un libro mas vendido"
masVendido' [c] m = c
masVendido' (c:cs) m = let ventasActual      = case lookupM c m of 
                                                 Nothing    -> error "el codigo debe estar asociado a un valor (stock, ventas)"
                                                 Just clave -> snd(clave)
                           codigoMasVendido  = masVendido' cs m 
                           masVendidoDeTodos = case lookupM codigoMasVendido m of
                                                 Nothing    -> 0
                                                 Just valor -> snd(valor)
                       in if ventasActual > masVendidoDeTodos
                          then c
                          else codigoMasVendido

-- =====================================================================
--  FUNCIONES YA IMPLEMENTADAS (NO son parte del parcial)
--  Están para que puedas probar. OJO: "reponer" se parece mucho a
--  "vender". Si querés hacer vender sin ayuda, no la mires antes.
-- =====================================================================

nuevaLibreria :: Libreria
nuevaLibreria = Lib emptyM emptyS

registrar :: Codigo -> Libreria -> Libreria
registrar c (Lib m s) = Lib (assocM c (0, 0) m) s

stockDe :: Codigo -> Libreria -> Int
stockDe c (Lib m _) = case lookupM c m of
                        Just (stk, _) -> stk
                        Nothing       -> error "stockDe: el libro no está registrado"

disponibles :: Libreria -> [Codigo]
disponibles (Lib _ s) = set2list s

-- (más abajo, a propósito, para que no la veas sin querer)

reponer :: Codigo -> Cantidad -> Libreria -> Libreria
reponer c n (Lib m s) = case lookupM c m of
                          Just (stk, ven) -> Lib (assocM c (stk + n, ven) m) (addS c s)
                          Nothing         -> error "reponer: el libro no está registrado"