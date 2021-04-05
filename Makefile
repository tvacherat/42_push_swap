RM			=	rm -rf
LIBFT_DIR	=	libft
CHECKER_DIR	=	checker_dir
PS_DIR		=	push_swap_dir
LIBFT		=	$(LIBFT_DIR)/libft.a
CHECKER		=	checker
PUSH_SWAP	=	push_swap

_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]
_CLEAR		=	\033[2K\c

all				:	$(LIBFT) $(CHECKER) $(PUSH_SWAP)
					@ $(shell cp $(CHECKER_DIR)/$(CHECKER) . )
					@ $(shell cp $(PS_DIR)/$(PUSH_SWAP) . )

$(LIBFT)		:
					@ $(MAKE) --silent -C $(LIBFT_DIR)

$(CHECKER)		:
					@ $(MAKE) --silent -C $(CHECKER_DIR)

$(PUSH_SWAP)	:
					@ $(MAKE) --silent -C $(PS_DIR)

clean			:
					@ echo "$(_INFO) Deleted object files and directories"
					@ $(MAKE) fclean --silent -C $(LIBFT_DIR) > /dev/null 2>&1
					@ $(MAKE) fclean --silent -C $(CHECKER_DIR) > /dev/null 2>&1
					@ $(MAKE) fclean --silent -C $(PS_DIR) > /dev/null 2>&1
					@ echo "$(_SUCCESS) Working directory clean"

fclean			:	
					@ echo "$(_INFO) Deleted object files and directories"
					@ $(RM) $(PUSH_SWAP) $(CHECKER)
					@ $(MAKE) fclean --silent -C $(LIBFT_DIR) > /dev/null 2>&1
					@ $(MAKE) fclean --silent -C $(CHECKER_DIR) > /dev/null 2>&1
					@ $(MAKE) fclean --silent -C $(PS_DIR) > /dev/null 2>&1
					@ echo "$(_SUCCESS) Working directory clean"

re				: 	fclean all

bonus			:	all

norminette		:
					@ $(MAKE) norminette -C $(CHECKER_DIR)
					@ $(MAKE) norminette -C $(PS_DIR)
					@ $(MAKE) norminette -C $(LIBFT_DIR)

.PHONY: 		all fclean clean re
