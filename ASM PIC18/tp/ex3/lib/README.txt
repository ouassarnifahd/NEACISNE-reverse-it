Tutoriel de création de librairie sous Windows depuis la toolsuite C32 de Microchip
sous MPLAB X. Utilisation de l'archiver (génération de Librairie). lien internet, C32 toolsuite Microchip : 

	http://ww1.microchip.com/downloads/en/devicedoc/33014j.pdf


>> Lancer le terminal windows

	- Solution n°1 : Démarrer -> exécuter -> cmd -> OK
	- Solution n°2 : touche [windows] + touche [R] -> cmd -> OK   


>> Accéder au lecteur C:\

	- Saisir C: -> Entrée


>> Aller sous le repertoire : Nom_projet\lib 

	- Copier le chemin depuis l'interface GUI 

	- Clic droit sur le terminal de commande -> coller


>> Retirer le fichier main.c de votre projet puis compilez votre programme. Vous aurez une erreur à la compilation qui est normale !


>> copier les fichiers objets compilés dans le répertoire lib :

	- Sources (chemin fixe sous MPLAB X, ne peut pas être modifié) :
	.\Nom_projet.X\build\default\debug\_ext\??chiffre??
	
	- Destination :
	.\lib 

	- Commande windows :
	copy ..\Nom_projet.X\build\default\debug\_ext\??chiffre??\*.o .\	



>> Génération de la librairie :

	- Saisir :
	mplib /c nom_lib.lib nom_fichier1.o nom_fichier2.o nom_fichier3.o nom_fichier4.o


>> La librairie est maintenant créée et est prête à être ajoutée à votre projet pour utilisation
