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
Le deuxième capteur est positionné à l'intérieur, il permet cette fois-ci, avec une marque à l'interieur des roues, de repérer quand la roue fait un tour complet. Dans ce même programme on compte le nombre de tour que l'on a fait. Il faut maintenant que je lie ses deux informations pour pouvoir connaitre sur quel motif nous nous sommes stoppés.
