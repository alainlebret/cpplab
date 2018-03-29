# Chiffrement XOR
## Méthode
Le système de chiffrement/déchiffrement XOR (ou exclusif) répond au schéma fonctionnel suivant :

![XOR](tp10/xor.png)

Les données sont chiffrées bit à bit à l'aide de la clef, cette dernière étant répétée autant de fois que nécessaire. L'intérêt de cette opération est sa réversibilité.

## Table de vérité du OU exclusif

| a    | b    | a ^ b |
|------|------|-------|
| 0    | 0    | 0     |
| 0    | 1    | 1     |
| 1    | 0    | 1     |
| 1    | 1    | 0     |

## Exemple

donnée = P = 0x50

clef   = t = 0x74

donnée chiffrée  = P ^ t = $

donnée déchiffrée = $ ^ t = P