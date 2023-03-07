FROM debian:buster

RUN apt-get update && apt-get upgrade -y
RUN apt-get install nginx -y
RUN apt-get install openssl -y

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
    -subj "/C=FR" \
    -out /etc/nginx/ssl/inception.crt \
    -keyout /etc/nginx/ssl/inception.key

COPY conf/nginx.conf /etc/nginx/conf.d/

RUN mkdir -p /run/nginx

EXPOSE 443 9000

CMD [ "nginx", "-g", "daemon off;" ]
