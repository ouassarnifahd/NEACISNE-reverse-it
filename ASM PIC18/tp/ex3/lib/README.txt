Tutoriel de cr�ation de librairie sous Windows depuis la toolsuite C32 de Microchip
sous MPLAB X. Utilisation de l'archiver (g�n�ration de Librairie). lien internet, C32 toolsuite Microchip : 

	http://ww1.microchip.com/downloads/en/devicedoc/33014j.pdf


>> Lancer le terminal windows

	- Solution n�1 : D�marrer -> ex�cuter -> cmd -> OK
	- Solution n�2 : touche [windows] + touche [R] -> cmd -> OK   


>> Acc�der au lecteur C:\

	- Saisir C: -> Entr�e


>> Aller sous le repertoire : Nom_projet\lib 

	- Copier le chemin depuis l'interface GUI 

	- Clic droit sur le terminal de commande -> coller


>> Retirer le fichier main.c de votre projet puis compilez votre programme. Vous aurez une erreur � la compilation qui est normale !


>> copier les fichiers objets compil�s dans le r�pertoire lib :

	- Sources (chemin fixe sous MPLAB X, ne peut pas �tre modifi�) :
	.\Nom_projet.X\build\default\debug\_ext\??chiffre??
	
	- Destination :
	.\lib 

	- Commande windows :
	copy ..\Nom_projet.X\build\default\debug\_ext\??chiffre??\*.o .\	



>> G�n�ration de la librairie :

	- Saisir :
	mplib /c nom_lib.lib nom_fichier1.o nom_fichier2.o nom_fichier3.o nom_fichier4.o


>> La librairie est maintenant cr��e et est pr�te � �tre ajout�e � votre projet pour utilisation
