-- =====================================================================
--  Map.hs - Implementación del TAD Map (ya hecha, NO es parte del parcial)
--  Respeta la interfaz del Anexo. Por dentro usa Data.Map, así que los
--  costos son los del anexo (O(log k)).
-- =====================================================================

module Map (Map, emptyM, assocM, lookupM, deleteM, keysM, sizeM) where

import qualified Data.Map as DM

newtype Map k v = M (DM.Map k v)

instance (Show k, Show v) => Show (Map k v) where
  show (M m) = show (DM.toList m)

emptyM :: Map k v
emptyM = M DM.empty

assocM :: Ord k => k -> v -> Map k v -> Map k v
assocM k v (M m) = M (DM.insert k v m)

lookupM :: Ord k => k -> Map k v -> Maybe v
lookupM k (M m) = DM.lookup k m

deleteM :: Ord k => k -> Map k v -> Map k v
deleteM k (M m) = M (DM.delete k m)

keysM :: Eq k => Map k v -> [k]
keysM (M m) = DM.keys m

sizeM :: Map k v -> Int
sizeM (M m) = DM.size m