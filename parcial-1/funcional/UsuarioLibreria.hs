-- =====================================================================
--  Usuario.hs - EJERCICIO 1
--  Funciones hechas COMO USUARIO del TAD Libreria: solo se puede usar la
--  interfaz (nuevaLibreria, registrar, reponer, vender, stockDe,
--  disponibles, masVendido). NO se ve la representación (Lib m s).
-- =====================================================================

module UsuarioLibreria (conMasStockQueElMasVendido) where

import Libreria

-- Propósito: dada una lista de códigos y una librería, devuelve los libros
--            de la lista cuyo stock supera estrictamente al stock del libro
--            más vendido.
-- Precondición: todos los códigos de la lista están registrados en la
--               librería y al menos un libro tiene ventas mayores a cero.
-- Eficiencia: O(N log N + K log N), siendo N la cantidad de libros de la
--             librería y K la cantidad de códigos de la lista.
--             masVendido es O(N log N) y se hace una sola vez; stockDe del
--             más vendido es O(log N); y la subtarea hace K veces stockDe,
--             que es O(log N).
conMasStockQueElMasVendido :: [Codigo] -> Libreria -> [Codigo]
conMasStockQueElMasVendido cs l = conMasStockQueElMasVendido' cs (stockDe (masVendido l) l) l

conMasStockQueElMasVendido' :: [Codigo] -> Int -> Libreria -> [Codigo]
conMasStockQueElMasVendido' [] _ _     = [] 
conMasStockQueElMasVendido' (c:cs) n l =
                             let stockLibro = stockDe c l
                             in if stockLibro > n
                                   then c : conMasStockQueElMasVendido' cs n l
                                   else conMasStockQueElMasVendido' cs n l
