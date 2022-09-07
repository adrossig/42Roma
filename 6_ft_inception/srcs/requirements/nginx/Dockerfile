FROM debian:buster

#Install all dependecies
RUN apt update && apt install -y \
    nginx openssl && \
    orm -fr /var/lib/apt/lists/*

COPY ./conf/nginx.conf /etc/nginx/sites-available/default

RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
		-keyout /etc/ssl/private/nginx.key \
		-out /etc/ssl/certs/nginx.crt \
		-subj "/C=IT/ST=RO/O=42RomaLuiss/CN=arossign.42.fr";

#And we start the nginx services
CMD ["nginx", "-g", "daemon off;"]
