# Compression RLE
## Introduction
Le stockage de données et la transmission de celles-ci sur un support nécessite que leur taille soit minimale. Pour ces raisons des algorithmes de compression divers sont proposés (RLE, Huffmann, LZH, etc.).

## Compression RLE
#### 1. Méthode
Soit la chaîne de caractères suivante :
```` 
   AAB10CCC2222WWWWWWWW3
````

On se donne un seuil à partir duquel on va compresser une séquence d'octets répétitifs, par exemple seuil = 4. 

La séquence d'octets répétitifs est alors remplacée par la chaîne suivante où `Cs`est un caractère spécial :

````
   Cs[nombre répétitions][octet à répéter]
````

la chaîne de caractères précédente donnera alors :
````
   AAB10CCCCs42Cs8W3
````

#### 2. Taux de compression
Le taux de compression est l'inverse du quotient de compression (c.-à-d. le quotient du nombre d'éléments dans la donnée compressée par le nombre d'éléments dans la donnée originale). Il est habituellement exprimé en pourcentage. 
Dans l'exemple de notre chaîne de caractères, on obtient un taux :

C = (21/15) x 100 = 140%

#### 3. Choix du caractère spécial
De manière arbitraire nous pouvons donner à `Cs` la valeur 255 du code ASCII.

#### 4. Les algorithmes de compression/décompression en pseudolangage
````
{----------------------}
{ PROCEDURE COMPRESSER }
{----------------------}
PROC compresser (FICHIER fichier, FICHIER fichierCompresse)
VAR octetPrecedent : OCTET;
    octetCourant : OCTET;
    nombreRepetitions : ENTIER;
    i: ENTIER;
DEBUT
    nombreRepetitions <- 1;  
    octetPrecedent <- lireOctet (fichier); 

    REPETER
        octetCourant <- lireOctet (fichier);

        SI (octetCourant = octetPrecedent) 
            nombreRepetitions <- nombreRepetitions + 1; 
        SINON
            SI (nombreRepetitions > seuil) 
                ecrireOctet(fichierCompresse, codeRepetition);  
                ecrireOctet(fichierCompresse, nombreRepetitions);
                ecrireOctet(fichierCompresse, octetPrecedent); 
            SINON
                SI (nombreRepetitions > 1)
                    POUR i <- 1 A nombreRepetitions
                        ecrireOctet(fichierCompresse, octetPrecedent);
		    FINP
                SINON
                    ecrireOctet(fichierCompresse, octetPrecedent);
	      	FINSI
            FINSI
            nombreRepetitions <- 1;
            octetPrecedent <- octetCourant;
        FINSI
    JUSQU'A (FIN fichier);
FIN
````

````
{------------------------}
{ PROCEDURE DECOMPRESSER }
{------------------------}
PROC decompresser (FICHIER fichierCompresse, FICHIER fichier)
VAR codeARepeter : OCTET;
    octetCourant : OCTET;
    nombreRepetitions : ENTIER; 
    i : ENTIER;

DEBUT
    TANTQUE (NON FIN fichierCompresse)
        octetCourant <- lireOctet(fichierCompresse)�;
        SI (octetCourant = codeRepetition) 
            nombreRepetitions <- lireOctet(fichierCompresse);
            codeARepeter <- lireOctet(fichierCompresse); 
            POUR i<-1 A nombreRepetitions
                ecrireOctet(fichier, codeARepeter); 
            FINP
        SINON 
            ecrireOctet (fichier, octetCourant);
        FINSI
    FINTQ
FIN
````
où :

````
lireOctet(FICHIER) : retourne un octet lu dans le fichier et incrémente le pointeur de fichier.
ecrireOctet(FICHIER, OCTET) : écrit un octet dans le fichier et incrémente le pointeur de fichier.
````
-----

## Exercice :
A partir de l'algorithme de compression RLE, effectuer une compression manuelle de la chaîne de caractères suivantes :
````
   IIINNNNNFOORRRrMMMMMMMAAAAAAATTTTTTTTIQUUUUEEEE
````

Déterminer la chaîne résultante pour un seuil de 4, et calculer le taux de compression obtenu (le caractère 255 sera remplacé dans votre chaîne par le caractère `$`).

