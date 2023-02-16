Rapport de séances:

Séance 1 du 14 décembre 2022:

Nous avons récupéré tous les composants utiles à notre projet d'un ancien projet de machine à sous, en le démontant.
Nous avons amélioré notre git hub, en précisant les fonctions à réaliser et le matériel necessaire pour le projet.
Nous avons créé des plans sur papier de la structure du projet en précisant toutes les dimensions.


Séance 2 du 4 janvier 2023:

Je me suis concentrée sur les roues, j'ai créé un programme permettant de faire tourner les roues et modulant la vitesse et le sens à l'aide d'un condensateur.  
Nous avons créé des équerres en aluminium pour pouvoir supporter le moteur et surélever les roues.
Les dimensions de ces équerres sont les suivantes: (3 fois la même)
![WhatsApp Image 2023-01-04 at 18 30 04](https://user-images.githubusercontent.com/119940151/210615158-91b0050e-1ef6-4d2e-b4c1-8c07a88257fc.jpeg)
Nous avons pris en compte des trous pour mettre des vis dans l'équerre afin de la fixer au socle.
![image](https://user-images.githubusercontent.com/119940151/210615632-26e83154-eaba-4a32-948e-85a3110865f3.png)
J'ai reflechi à comment placer les capteurs, les leds  et le sckotch noir afin d'initialiser la roue et de meusurer avec precision les rotations. (voir les vidéos: https://youtube.com/shorts/KpsiDmUDK2c?feature=share et https://youtube.com/shorts/4W6VaF1P170?feature=share)


Séance 3 du 11 janvier 2023:

Ma séance a été divisée en deux parties. Durant la première partie, je me suis concentrée sur le capteur, j'ai reglé sa précision pour qu'il puisse détecter le moment où la roue fait un tour complet (cette partie n'est pas encore totalement terminée). J'ai changé la position du capteur pour qu'il capte un point d'origine, au niveau du scotch noir, sur la face extérieure de la roue comme sur la photo ci-dessous.
![IMG-9374](https://user-images.githubusercontent.com/119940151/211874066-65351159-db79-4bae-a3e1-ce4ed914d1c7.jpg)
Dans une seconde partie avec ma binôme nous avons profité des outils à notre disposition pour pouvoir fixer les roues aux équerres et les équerres au socle. Ce n'est pas le montage definitif mais c'est avec cette disposition que nous allons espacer les roues.
![0502b98d-408d-4118-b525-b9df9910b219](https://user-images.githubusercontent.com/119940151/211877055-9e89e108-3ac6-492e-bd19-2f3b0c994628.JPG)
Pour finir j'ai pu faire tourner simultanément les 3 roues sur le support. Comme sur la video suivante: https://youtube.com/shorts/H7g4kApOgP4?feature=share 

Séance 4 du 18 janvier 2023:

Nous avons fixé les moteurs aux équerres à l'aide de riselans. Après avoir échangé avec nos professeurs, on a décidé d'apporter quelques changements à notre idée initiale pour pouvoir se repérer sur la roue. En effet, deux problèmes se posent à nous, d'une part il ne faut pas que la roue s'arrête entre deux motifs. D'autre part, il faut savoir sur quel motif la roue s'est arrêtée.
On a alors décidé qu'il y aurait deux capteurs pour chaque roue. L'un est à l'extérieur et à l'aide d'un repère (scotch noir), il capte à chaque fois que l'on passe devant un motif. J'ai créé cette fonction qui compte le nombre de motifs passés. 
Pour pouvoir m'approprier le fonctionnement j'ai aussi créé un programme (roues_avec_capteur1) qui s'arrête quand nous sommes passés devant 9 motifs par exemple. Le prolème de s'arrêter entre deux motifs est alors résolu.
Le deuxième capteur est positionné à l'intérieur, il permet cette fois-ci, avec une marque à l'interieur des roues, de repérer quand la roue fait un tour complet. Dans ce même programme on compte le nombre de tour que l'on a fait. Il faut maintenant que je lie ces deux informations pour pouvoir connaître sur quel motif nous nous sommes stoppés.

Séance 5 du 1 février 2023:

En amont de la séance j'avais travaillé sur le programme roues_avec_capteur1 (roues_avec_capteur1_version2), mais durant le cours je me suis concentrée sur la construction. Au cours de nos essais on s'est rendu compte que les roues ne tournaient pas droit. Elles n'étaient pas voilées mais cela était dû à un écart entre le moteur et la roue. On a alors poli une partie du moteur pour qu'il puisse se poser complétement à plat sur la roue, puis on du fixer le moteur à la roue en perçant et en vissant 4 vis, 4 boulons, 8 rondelles, pour chaque roue.
J'ai pris les mesures extactes pour savoir où fixer les capteurs. Puis on a percé les équerres pour pouvoir fixer les capteurs définitivement. Afin d'éviter les problèmes de conduction nous avons mis du plastique entre l'équerre et le capteur. On a alors à nouveau fixé la roue avec un serre flex. On a positionné le scotch noir au niveau de chaque motif pour que le capteur puisse recueillir l'information.
Durant cette séance une complication s'est produite puisque la roue (imprimée en 3D) s'est cassée, donc on a essayer de la refixer à l'aide du pistolet à colle pour pouvoir continuer le projet.


Séance 6 du 8 février 2023:

J'ai avancé sur la création du programme du jeu. Maintenant que les capteurs et une roue sont bien fixées, je peux effectuer des essais. 
![WhatsApp Image 2023-02-08 at 19 26 27](https://user-images.githubusercontent.com/119940151/217624841-1e67b4ed-a17d-4012-b785-f12be00f2542.jpeg)
J'ai cherché à améliorer le programme qui s'occupe des roues. Initialement j'utilisais la fonction random() qui permet de renvoyer un nombre pseudo-aléatoire dans l’intervalle spécifié par les valeurs min et max. En effet, elle me renvoyait alors tout le temps le même nombre, ce qui renverrais toujours le même schéma de jeu puisque l'on tomberait toujours sur le même motif. J'ai alors ajouté un générateur de nombres pseudo-aléatoires initialisé par la fonction randomSeed(analogRead(A1)). Elle s'initialise à partir d’une valeur aléatoire due au « bruit » sur le port. Désormais, nous ne pouvons pas savoir à l'avance sur quel motif la roue va s'arrêter.
J'ai créé le programme de façon à que dès qu'on le lance on sait sur quel motif la roue va s'arrêter en utilisant un numéro aléatoire. On fait alors ce nombre modulo 7 (qui correspond au nombre de motif), puis on utilise un break pour séparer les cas et savoir sur quel motif la roue va s'arrêter. Par la suite cela sera très utile pour savoir si les 3 motifs sont alignés.
Le programme des roues repère le motif sur lequel on se trouve en divisant par le nombre de motif le nombre de passage devant un motif.
Je rencontrais un problème pour arrêter totalement les roues, j'ai alors utilisé la fonction myservo.detach() quand le programme doit mettre les roues à l'arrêt.
J'ai créé une fonction roue avec ce programme pour pouvoir l'appeler dans la fonction loop et que le programme soit structurer. 
Par la suite, j'ai pu ajouter un bouton poussoir. Lorsque nous appuyons dessus les roues tournent (la fonction roue se lance) et les roues s'arrêtent aléatoirement. (voir vidéo: https://youtube.com/shorts/zzfbXRdjAug?feature=share )
En m'inspirant du programme compte pièce créé par Manon, j'ai ajouté une fonction similaire au programme. Le but est de pouvoir lancer la partie en appuyant sur le bouton uniqument si on a introduit une pièce dans la machine. Cette fonctionalité n'est pas encore terminée. 

Séance 7 du 16 février 2023:

Durant cette séance j'ai travaillé sur le programme qui permettra de faire fonctionner le jeu. Je me suis rendue compte que la fonction roue que j'avais créé ne pourrait pas être appelée 3 fois avec pour arguments à chaque fois un servo en argument différent. En effet, sinon, les roues se lancent une fois que l'autre est terminée. J'ai alors déclaré pour chaque roue les capteurs associées, celui de l'initialisation et celui des motifs. J'ai alors créée une boucle qui continue de tourner tant que toutes les roues ne sont pas arrêtées. Une fois toutes les roues arrêtées le programme renvoi l'information au joueur s'il a gagné ou pas, c'est à dire si le motif est le même pour les 3 roues ou pas. De plus, pour éviter que le programme ne fasse des calculs supplémentaires je ne lui fais compter que le tour d'initialisation. Avec toutes ces modifications, j'ai du rectifier pour que les roues se lancent uniquement lorsqu'on a pressé le bouton.
Le version 2 du programme de jeu est: 
