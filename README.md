Collision

İnsideMap Funktion: es wurde getestet, ob das Auto auf dem Gamewindow ist, sonst das Auto geht zurück zum Anfangpunkt.
Viele unterschiedliche Objekten wurden auf den Rennstrecken addiert und an dem decorArray gespeichert. 
Mit QDebug die richtige positionen der Objekten auf dem Debugfenster gelesen wurden.
Problem: die Größe des decorArrays musste für alle ‘’maps’’ passen.
crashed Funktion: man vergleicht das current position vom Auto mit dem Objektposition, wenn die beide das selbe Position haben, dann bekommen wir ein collision.

Map Design 

Scene in background image ina 3 farkli map image kullandik ve yazdigimiz fonksiyonlarla addItemla su, ağaç vs ekledik.
Jede Rennstrecke teilt sich an Rechtecke mit unterschiedlichen großen und wurde an einem roadArray speichern, damit wir die Grenzen bestimmen können.
Problem: die Größe des roadArrays musste für alle ‘’maps’’ passen.
Mit der InsideRoad Funktion wurde getestet, ob das Auto auf der Rennstrecke ist, sonst das Auto faehrt langsamer.
Sonunda 3 farkli map elde ettik
