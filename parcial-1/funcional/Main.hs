-- =====================================================================
--  Main.hs - Pruebas del Parcial Librería, Parte 1
--
--  Compilar y correr:   runghc Main.hs
--  (o en ghci:  :l Main.hs   y después   main)
--
--  Hasta que no implementes vender y masVendido, las pruebas que las usan
--  van a cortar con "Prelude.undefined". Es normal.
-- =====================================================================

import Libreria
import UsuarioLibreria

-- Librería de prueba:
--   A: repone 5, vende 3  -> stock 2, ventas 3   (el más vendido)
--   B: repone 2, vende 2  -> stock 0, ventas 2   (sin stock)
--   C: repone 10, vende 1 -> stock 9, ventas 1
--   D: repone 4           -> stock 4, ventas 0
libPrueba :: Libreria
libPrueba =
    vender "C"
  $ vender "B" $ vender "B"
  $ vender "A" $ vender "A" $ vender "A"
  $ reponer "D" 4 $ reponer "C" 10 $ reponer "B" 2 $ reponer "A" 5
  $ registrar "D" $ registrar "C" $ registrar "B" $ registrar "A"
  $ nuevaLibreria

main :: IO ()
main = do
  putStrLn "===== EJERCICIO 3 ====="
  putStrLn ("stockDe A:  " ++ show (stockDe "A" libPrueba))        -- 2
  putStrLn ("stockDe B:  " ++ show (stockDe "B" libPrueba))        -- 0
  putStrLn ("stockDe C:  " ++ show (stockDe "C" libPrueba))        -- 9
  putStrLn ("disponibles: " ++ show (disponibles libPrueba))       -- A, C y D (en cualquier orden), sin B
  putStrLn ("masVendido: " ++ show (masVendido libPrueba))         -- "A"

  putStrLn ""
  putStrLn "===== EJERCICIO 1 ====="
  -- El más vendido es A, con stock 2. Libros con stock > 2: C (9) y D (4).
  putStrLn (show (conMasStockQueElMasVendido ["A", "B", "C", "D"] libPrueba))  -- ["C","D"]
  putStrLn (show (conMasStockQueElMasVendido ["B", "A"] libPrueba))            -- []
  putStrLn (show (conMasStockQueElMasVendido [] libPrueba))                    -- []