NAME = ircserv

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

DEPS = ${OBJS:.o=.d}

INC =   \

SRCS =	Command_CAP_LS.cpp \
		Command_INVITE.cpp \
		Command_JOIN.cpp \
		Command_KICK.cpp \
		Command_NICK.cpp \
		Command_NOTICE.cpp \
		Command_PASS.cpp \
		Command_MODE.cpp \
		Command_PINGPONG.cpp \
		Command_PART.cpp \
		Command_PRIVMSG.cpp \
		Command_QUIT.cpp \
		Command_TOPIC.cpp \
		Command_USER.cpp \
		Channel.cpp \
		Commands.cpp \
		Client.cpp \
		Server.cpp \
		Signals.cpp \
		main.cpp  \

OBJS_PATH = ./objs
OBJS_NAMES = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAMES))

TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE = 0
PERCENTAGE = 0

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BOLD = \e[1m
UNBOLD = \e[0m
UNCOLOR = \033[0m

define update_progress
    $(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
    $(eval PERCENTAGE=$(shell echo $$(($(CURRENT_FILE)*100/$(TOTAL_FILES)))))
	@printf "$(GREEN)\rCompiling [%-20s] %d%% $(UNCOLOR)" "####################" "$(PERCENTAGE)"
endef

all : $(NAME)

$(NAME): $(OBJS) $(INC)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(BOLD)$(NAME)$(UNBOLD) is built 🪄$(UNCOLOR)"

$(OBJS_PATH)/%.o: %.cpp
	@mkdir -p $(OBJS_PATH)
	$(call update_progress)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean :
	@rm -rf $(OBJS_PATH)
	@rm -rf $(DEPS)
	@echo "$(YELLOW)cleaning 🧽$(UNCOLOR)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED)full clean 🧹$(UNCOLOR)"

re: fclean all

-include $(DEPS)

.PHONY:    all clean fclean re bonus
