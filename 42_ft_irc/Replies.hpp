#pragma once

/*
https://datatracker.ietf.org/doc/html/rfc2812#section-5
*/
/*COMMON REPLIES*/
# define NEEDMOREPARAMS_ERR(command) (": localhost 461 " + command + " :Not enough parameters" + "\r\n")

# define RPL_WELCOME(userName, nickname) (":localhost 001 " + nickname + " :Welcome to the Internet Relay Network " + nickname + "!" + userName + "\r\n")
# define RPL_YOURHOST(client, servername, version) (":localhost 002 " + client + " :Your host is " + servername + " , running version " + version + "\r\n")
# define RPL_CREATED (": localhost 003 " + "This server was created <date>")
# define RPL_MYINFO (": localhost 004 " + "<servername> <version> <available user modes>" +  "<available channel modes>")

/* PASS ERROR REPLIES */
# define ALREADYREGISTRED_ERR ": localhost 462 :Unauthorized command (already registered)\r\n"

/* NICK ERROR REPLIES */
# define NONICKNAMEGIVEN_ERR ":localhost 431 :No nickname given\r\n"
# define ERRONEUSNICKNAME_ERR(nickname) (":localhost 432 " + nickname + " :Erroneous nickname" + "\r\n")
# define NICKNAMEINUSE_ERR(nickname) (":localhost 433 " + nickname + ":Nickname is already in use" + "\r\n")

/* PRIVMSG REPLIES */
# define ERR_NOSUCHNICK(nickname) (":localhost 401 " + nickname + " :No such nick/channel\r\n")
# define ERR_CANNOTSENDTOCHAN(channelname) (": localhost 404 " + channelname + " :Cannot send to channel\r\n")
# define ERR_TOOMANYTARGETS(target) (":localhost 407 " + target + " :Duplicate recipients/no message delivered\r\n")
# define ERR_NOTEXTTOSEND ": localhost 412 :No text to send\r\n"
# define ERR_NORECIPIENT(command) (": localhost 411 :No recipient given " + command + "\r\n")

/* INVITE ERROR REPLIES */
# define NOSUCHCHANNEL_ERR(channel) (":localhost 403 " + channel + " :No such channel" + "\r\n")
# define USERNOTINCHANNEL_ERR(client, nickname, channel) (":localhost 441 " + client + " " + nickname + " " + channel + " :They aren't on that channel" + "\r\n")
# define NOTONCHANNEL_ERR(client, channel) (":localhost 442 " + client + " " + channel + ":You're not on that channel" + "\r\n")
# define USERONCHANNEL_ERR(client, nickname, channel) (":localhost 443 " + client + " " + nickname + " " + channel + " :is already on channel" + "\r\n")
# define CHANOPRIVSNEEDED_ERR(channel) (":localhost 482 " + channel + " :You're not channel operator" + "\r\n")
# define ERR_TOOMANYCHANNELS(client, channel) (":localhost 405 " + client + " " + channel + " :You have joined too many channels" + "\r\n")
# define ERR_CHANNELISFULL(client, channel) (":localhost 471 " + client + " " + channel + " :Cannot join channel (+l)" + "\r\n")
# define ERR_INVITEONLYCHAN(client, channel) (":localhost 473 " + client + " " + channel + " :Cannot join channel (+i)" + "\r\n")
# define ERR_BADCHANNELKEY(client, channel) (":localhost 475 " + client + " " + channel + " :Cannot join channel (+k)" + "\r\n")
# define ERR_INVALIDKEY(client, channel) (":localhost 525 " + client + " " + channel + " :Key is not well-formed" + "\r\n")

# define RPL_KICK(user_id, channel, kicked, reason) (user_id + " KICK " + channel + " " + kicked + " " + reason + "\r\n")
# define RPL_PART(user_id, channel, reason) (user_id + " PART " + channel + " " + reason + "\r\n")
# define RPL_QUIT(user_id, reason) (user_id + " QUIT " + reason + "\r\n")

# define RPL_INVITE(user_id, invited, channel) (user_id + " INVITE " + invited + " :" + channel + "\r\n")
# define RPL_INVITING(client, nick, channel) (":localhost 341 " + client + " " + nick + " " + channel + "\r\n");

# define RPL_MODE(user_id, channel, modeset, target) (user_id + " MODE " + channel + " " + modeset + " " + target + "\r\n")
# define RPL_CHANNELMODEIS(client, channel, modestring) (":localhost 324 " + client + " " + channel + " " + modestring + "\r\n")
# define UNKNOWNMODE_ERR(modeChar, channel) (":localhost 472 " + std::string(1, modeChar) + " :is unknown mode char to me for " + channel + "\r\n")
# define KEYSET_ERR(channel) (":localhost 467 " + channel + ":Channel key already set" + "\r\n")

# define RPL_NOTOPIC(client, channel) (":localhost 331 " + client + " " + channel + " :No topic is set" + "\r\n")
# define RPL_TOPIC(client, channel, topic) (":localhost 332 " + client + " " + channel + " " + topic + "\r\n")
# define RPL_TOPICWHOTIME(client, channel, nick, setat) (":localhost 333 " + client + " " + channel + " " + nick + " " + setat + "\r\n")

# define RPL_NAMREPLY(client, channel, list) (":localhost 353 " + client + " = " + channel + " :" + list + "\r\n")
# define RPL_ENDOFNAMES(client, channel) (":localhost 366 " + client + " " + channel + " :End of /NAMES list" + "\r\n")

# define userID(nickname, username) (":" + nickname + "!" + username + "@localhost")
