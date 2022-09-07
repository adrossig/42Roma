BLUE=\033[0;34m
GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;33m
NC=\033[0m
B=`tput bold`

VOL =	srcs_db_vol \
		srcs_wp_vol

FC =	${GREEN}${B}CLEAN${NC}
NOC =	${RED}${B}No	${NC}

all: help

help:
	@clear
	@echo "\n${B}HELP:\n"
	@echo "${B}1 -> make run:${GREEN}${B} Init all services, containers, images and volumes.${NC}"
	@echo "${B}2 -> make build:${GREEN}${B} Build a new container with old volumes.${NC}"
	@echo "${B}3 -> make stop:${GREEN}${B} Stop and removes the containers with their images.${NC}"
	@echo "${B}4 -> make fclean:${GREEN}${B} Performs the same as clean and removes also volumes.${NC}"
	@echo "${B}5 -> make run:${GREEN}${B} Clean and execute all.\n${NC}"
	@echo "${B}6 -> make log:${GREEN}${B} To see the log.\n${NC}"

run:
	@sudo mkdir -p /home/${USER}/data/wordpress
	@sudo mkdir -p /home/${USER}/data/mariadb
	@sudo docker-compose -f ./srcs/docker-compose.yml up --build -d

clean: 
	clear
	@echo "\n${BLUE}${B}Loading...${NC}
	@echo "${B}._______________________________."
	@echo "${B}| Volumes | Containers | Images |"
	@echo "${B}|_________|____________|________|"
	@echo "${B}|         |            |        |"
	@echo "${B}| ${NOC}  |  ${FC}     | ${FC}  |"
	@echo "${B}|         |            |        |"
	@echo "${B}|_________|____________|________|"
	@sudo docker-compose -f ./srcs/docker-compose.yml down --rmi all -v
	
fclean:
	clear
	@echo "\n${BLUE}${B}Loading...${NC}
	@echo "${B}._______________________________."
	@echo "${B}| Volumes | Containers | Images |"
	@echo "${B}|_________|____________|________|"
	@echo "${B}|         |            |        |"
	@echo "${B}| ${FC}   |  ${FC}     | ${FC}  |"
	@echo "${B}|         |            |        |"
	@echo "${B}|_________|____________|________|"
	@make clean
	@sudo rm -fr /home/${USER}/data

stop:
	@sudo docker-compose -f ./srcs/docker-compose.yml down -v

log:
	@sudo docker-compose -f ./srcs/docker-compose.yml logs -f

re: fclean run
