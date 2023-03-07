# service mysql start;

# mysql -e "CREATE DATABASE IF NOT EXISTS \`$SQL_DB\` CHARACTER SET utf8 COLLATE utf8_general_ci;"
# mysql -e "CREATE USER IF NOT EXISTS \`$SQL_USER\`@'%' IDENTIFIED BY \`$SQL_PASSWORD\`;"
# mysql -e "GRANT ALL PRIVILEGES ON \`$SQL_DB\`.* TO \`$SQL_USER\`@'%';"
# mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY \`$SQL_ROOT_PASSWORD\`;"
# mysql -e "FLUSH PRIVILEGES;"

# mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown

# exec mysqld_safe

if [ ! -d /var/lib/mysql/${SQL_DB} ]; then
    mysqld&
    until mysqladmin ping; do
        sleep 2
    done
    mysql -u root -e "CREATE DATABASE ${SQL_DB};"
    mysql -u root -e "CREATE USER 'root'@'%' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
    mysql -u root -e "GRANT ALL ON *.* TO 'root'@'%';"
    mysql -u root -e "CREATE USER '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
    mysql -u root -e "GRANT ALL ON ${SQL_DB}.* TO '${SQL_USER}'@'%';"
    mysql -u root -e "DELETE FROM mysql.user WHERE user='root';"
    mysql -u root -e "FLUSH PRIVILEGES;"
    killall mysqld
fi

mysqld
