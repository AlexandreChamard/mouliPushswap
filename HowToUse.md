faire des fichiers de config:

serie: 10 {
	calls: 4
}
va faire 4 serie de 10 nombres

serie: 100, 10 {
	calls: 4
}
va faire 4 serie de 10 nombres puis 4 serie de 100 nombres

config:
min:		set le nombre min (si min = 0: tout les nombres seront positif)
max:		set le nombre max (si max = 0: tout les nombres seront negatif)
calls:		set le nombre de d'appel
seed:		set la seed du random (pour avoir toujours les mêmes entrées)
debug:		mode pas à pas: 1 pour activer / 0 pour désactiver (déconseillé si calls > ~5)
verbose:	print la sortie du push_swap: 1 pour activer / 0 pour désactiver (déconseillé si la serie > ~1000)
timeout:	set le timeout (en second); -1 pour le désactiver

valeur par default:
min:		-50.000
max:		50.000
calls:		10
seed:		basé sur le time
debug:		0
verbose:	0
timeout:	10
serie min:	1
serie max:	100.000

si les configs sont placé dans une serie, elles seront effecives seulement pour la serie.
si les configs sont placé en dehors d'une serie, elles seront effecives pour toutes les series en dessous.
