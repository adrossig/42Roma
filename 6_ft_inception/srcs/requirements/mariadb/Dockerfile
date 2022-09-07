FROM debian:buster

#Install all dependecies
RUN apt update && apt install -y \
    mariadb-server && \
    rm -fr /var/lib/lists/*


RUN rm /etc/mysql/maraidb.conf.d/50-server.cnf

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d
COPY ./tools/create_user.sh /

RUN bash ./create_user.sh
RUN rm -fr create_user.sh

EXPOSE 3306

ARG DB_NAME=${DB_NAME}
ARG DB_USER=${DB_USER}
ARG DB_PASSWORD=${DB_PASSWORD}
ARG DB_ROOT_PASSWORD=${DB_ROOT_PASSWORD}

CMD ["mysqld_safe"]
