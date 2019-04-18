# fillit
 C’est l’histoire d’une pièce de Tetris, d’un petit carré et d’un(e) dev qui entrent dans un bar...
 
 Liste des différents Tetriminos.
<img src="https://cdn.discordapp.com/attachments/403918603914838018/568367519631540224/tetriminos-list.png"
     alt="tetriminos liste" />
 
 
 Exemple d'entrée/sortie.
 <img src="https://cdn.discordapp.com/attachments/403918603914838018/568367969550336003/tetriminos-io-exemples.png"
     alt="tetriminos liste" />
     
 Tetriminos valides & invalides.
 <img src="https://cdn.discordapp.com/attachments/403918603914838018/568368484883365898/tetriminos-valid-invalid.png"
     alt="tetriminos liste" />
     
 On essaie de placer toutes les pièces, tant qu'une pièce est impossible à placer, on déplace la précédente et on réessaie. Si toutes les combinaisons ont été testées et qu'il n'est toujours pas possible d'y placer toutes les pièces, on agrandit le plateau de 1x1 et on recommence de la première pièce.
 <img src="https://cdn.discordapp.com/attachments/403918603914838018/568369228596379649/tetriminos-place-try-move.png"
     alt="tetriminos liste" />
     
