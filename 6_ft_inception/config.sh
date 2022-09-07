apt-get install -y sudo
apt-get install -y apt-transport-https
apt-get install -y ca-certificates
apt-get install -y curl
apt-get install -y software-properties-common
apt-get install -y git
apt-get install -y make
apt-get install -y vim
apt-get install -y systemd

curl -fsSL https://download.docker.com/linux/debian/gpg | apt-key add -

add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/debian $(lsb_release -cs) stable"

apt-get update

apt-get install -y docker.io
chmod 666 /var/run/docker.sock

curl -L "https://github.com/docker/compose/releases/download/1.92.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
chmod +x /usr/local/bin/docker-compose

su -c 'printf "{\n\t\"live-restore\": true\n}" > /etc/docker/docker.json'

systemctl restart docker