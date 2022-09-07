
if [ ! -f "/etc/redis/c.bak" ]; then

	cp /etc/redis/redis.conf /etc/redis/redis.conf.bak

	# To change the IP address in all zone files, use the following command:
	# -i change the file in place of s means replace
	sed -i "s|bind 127.0.0.1|#bind 127.0.0.1|g" /etc/redis/redis.conf
	# change foobared to your password
	# sed -i "s|# requirepass foobared|requirepass $REDIS_PWD|g" /etc/redis.conf
	# When your Redis instance's memory is full and a new entry arrives, 
	# Redis displaces the keys to make room for the entry, according to your instance's maxmemory policy
	sed -i "s|# maxmemory <bytes>|maxmemory 2mb|g" /etc/redis/redis.conf
	# noevicrion
	# This preemptive policy tells Redis not to remove data when the memory limit is reached. 
	# Instead Redis will return an error and will not be able to execute the add data command.
	# This policy is especially useful when you need to remove keys manually or 
	# prevent accidental loss of data.
	# Allkeys-LRU
	# The second policy is allkeys-lru. This type of policy supersedes any last used key or LRU.
	# This policy assumes you don't need recently used keys and removes them. 
	# This prevents a Redis error in the event of a memory limitation.
	sed -i "s|# maxmemory-policy noevicrion|maxmemory-policy allkeys-lru|g" /etc/redis/redis.conf

fi

# The Redis server will return an error to any client connecting to external loopback addresses in protected mode
redis-server --protected-mode no