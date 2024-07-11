
# se connecter à un serveur: `/connect DALnet`
# export les logs send/receive: `/rawlog open ~/IRC/t.log`

# ft_irc
L’objectif de ce projet est de reproduire le fonctionnement d’un serveur IRC.

- doc complete officielle:
[Protocol](https://tools.ietf.org/html/rfc1459)
[Architecture](https://tools.ietf.org/html/rfc2810)
[Channel Management](https://tools.ietf.org/html/rfc2811)
[Client](https://tools.ietf.org/html/rfc2812)
[Server Protocol](https://tools.ietf.org/html/rfc2813) plus d' infos sur le formatage replies

- Résumé de la doc: https://modern.ircdocs.horse/#errneedmoreparams-461

- exemple d'un IRC: http://chi.cs.uchicago.edu/chirc/index.html

- les commandes: https://www.techbull.com/techbull/guide/internet/irccommande.html#msg

- guide pour la programmation reseau/socket:
http://vidalc.chez.com/lf/socket.html
https://www.codequoi.com/programmation-reseau-via-socket-en-c/

- `socket` Crée un nouveau point de terminaison de communication, un socket.
- `close` Ferme un fichier ou un socket.
- `setsockopt` Configure des options sur un socket.
- `getsockname` Obtient le nom local associé à un socket.
- `getprotobyname` Obtient une structure de données associée à un protocole par son nom.
- `gethostbyname` Obtient des informations sur l'hôte (adresse IP) par son nom.
- `getaddrinfo` Convertit un nom d'hôte et/ou un service en informations sur l'adresse.
- `freeaddrinfo` Libère la mémoire allouée par la fonction getaddrinfo.
- `bind` Associe une adresse à un socket.
- `connect` Établit une connexion avec un socket.
- `listen` Met un socket en mode d'écoute pour les connexions entrantes.
- `accept` Accepte une connexion entrante sur un socket.
- `htons` Convertit une valeur courte (16 bits) de l'ordre des octets de l'hôte à l'ordre des octets du réseau (Big-Endian).
- `htonl` Convertit une valeur longue (32 bits) de l'ordre des octets de l'hôte à l'ordre des octets du réseau.
- `ntohs` Convertit une valeur courte de l'ordre des octets du réseau à l'ordre des octets de l'hôte.
- `ntohl` Convertit une valeur longue de l'ordre des octets du réseau à l'ordre des octets de l'hôte.
- `inet_addr` Convertit une chaîne représentant une adresse IP en forme binaire.
- `inet_ntoa` Convertit une adresse IP en forme binaire en une chaîne lisible.
- `send` Envoie des données sur un socket.
- `recv` Reçoit des données depuis un socket.
- `signal` Configure le traitement d'un signal.
- `sigaction` Permet une gestion plus avancée des signaux que signal.
- `lseek` Modifie la position du curseur dans un fichier.
- `fstat` Obtient des informations sur un fichier ouvert.
- `fcntl` Modifie les propriétés d'un descripteur de fichier.
- `poll` Suspend l'exécution jusqu'à ce qu'un événement se produise sur un descripteur de fichier.

**1.1 Servers**
---
Servers are uniquely identified by their name, which has a maximum
length of sixty three (63) characters.

**1.2 Clients**
---
For each client all servers MUST have the following information: a
netwide unique identifier (whose format depends on the type of
client) and the server which introduced the client.

**1.2.1 Users**
---
Each user is distinguished from other users by a unique nickname
having a maximum length of nine (9) characters.

**1.2.2 Services**
---
Each service is distinguished from other services by a service name
composed of a nickname and a server name. As for users, the nickname
has a maximum length of nine (9) characters.

**1.3 Channels**
---
Channels names are strings (beginning with a '&', '#', '+' or '!'
character) of length up to fifty (50) characters.  Apart from the
requirement that the first character is either '&', '#', '+' or '!',
the only restriction on a channel name is that it SHALL NOT contain
any spaces (' '), a control G (^G or ASCII 7), a comma (',').  Space
is used as parameter separator and command is used as a list item
separator by the protocol.  A colon (':') can also be used as a
delimiter for the channel mask.  Channel names are case insensitive.

***See the protocol grammar rules (section 2.3.1)***

