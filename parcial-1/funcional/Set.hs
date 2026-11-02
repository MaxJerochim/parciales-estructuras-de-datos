-- =====================================================================
--  Set.hs - Implementación del TAD Set (ya hecha, NO es parte del parcial)
--  Respeta la interfaz del Anexo. Como la interfaz pide solo Eq (no Ord),
--  por dentro es una lista sin repetidos: addS, deleteS y belongsS son
--  O(n) acá en vez de O(log n). Para el parcial usá los costos del anexo.
-- =====================================================================

module Set (Set, emptyS, isEmptyS, addS, deleteS, belongsS, sizeS, set2list) where

data Set a = S [a] Int   -- elementos sin repetidos, cantidad

instance Show a => Show (Set a) where
  show (S xs _) = "{" ++ show xs ++ "}"

emptyS :: Set a
emptyS = S [] 0

isEmptyS :: Set a -> Bool
isEmptyS (S _ n) = n == 0

addS :: Eq a => a -> Set a -> Set a
addS x s@(S xs n) = if elem x xs then s else S (x : xs) (n + 1)

deleteS :: Eq a => a -> Set a -> Set a
deleteS x s@(S xs n) = if elem x xs then S (filter (/= x) xs) (n - 1) else s

belongsS :: Eq a => a -> Set a -> Bool
belongsS x (S xs _) = elem x xs

sizeS :: Set a -> Int
sizeS (S _ n) = n

set2list :: Set a -> [a]
set2list (S xs _) = xs