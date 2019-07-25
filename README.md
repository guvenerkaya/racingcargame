Map Design 

Drei verschiedene Rennstrecken wurde eingebaut.Auf Scene wurden drei verschiedene Bilder als Hintergrund eingestellt
und darauf wurden viele unterschiedliche Objekten z.B Wasseranteile,Baeume, Zuschauer usw. mit dem addItem() hinzugefügt.

Jede Rennstrecke teilt sich an Rechtecke mit unterschiedlichen großen und wurde an einem roadArray speichern,
damit wir die Grenzen bestimmen können.
Mit der InsideRoad Funktion wurde getestet, ob das Auto auf der Rennstrecke ist, sonst das Auto faehrt langsamer.

Collision

İnsideMap Funktion: es wurde getestet, ob das Auto auf dem Gamewindow ist, sonst das Auto geht zurück zum Anfangpunkt.

Viele unterschiedliche Collisionpunkte wurden bestimmt und an dem decorArray gespeichert. 
Mit QDebug Funktion wurden die richtige Positionen den Objekten auf dem Debugfenster gelesen.
crashed Funktion: man vergleicht das current position vom Auto mit dem Objektposition, wenn die beide das selbe Position haben, 
dann bekommen wir ein collision und  das Auto geht zurück zum Anfangpunkt.


