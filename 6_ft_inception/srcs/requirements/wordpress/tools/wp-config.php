<?php
/**
 * Custom WordPress configurations on "wp-config.php" file.
 *
 * This file has the following configurations: MySQL settings, Table Prefix, Secret Keys, WordPress Language, ABSPATH and more.
 * For more information visit {@link https://codex.wordpress.org/Editing_wp-config.php Editing wp-config.php} Codex page.
 * Created using {@link http://generatewp.com/wp-config/ wp-config.php File Generator} on GenerateWP.com.
 *
 * @package WordPress
 * @generator GenerateWP.com
 */


/* MySQL settings */
define( 'DB_NAME',     'db-name' );
define( 'DB_USER',     'db_user' );
define( 'DB_PASSWORD', 'db_password' );
define( 'DB_HOST',     'mariadb:3306' );
define( 'DB_CHARSET',  'utf8' );
define( 'DB_COLLATE',  '' );

define( 'WP_DEBUG', false );
define( 'WP_REDIS_HOST', 'redis' );
define( 'WP_CACHE_KEY_SALT', 'wp-docker-5DknvYepdjyJMo8gDqrLhrpAJUQ' );
define( 'WP_REDIS_PORT', '6379' );
define( 'WP_REDIS_TIMEOUT', 1 );
define( 'WP_REDIS_READ_TIMEOUT', 1 );
define( 'WP_REDIS_DATABASE', 0 );

/* MySQL database table prefix. */
$table_prefix = 'wp_';

/* Authentication Unique Keys and Salts. */
/* https://api.wordpress.org/secret-key/1.1/salt/ */
define('AUTH_KEY',         'c0iQRggtR::yfYRKK|Jylm_-GGLBoGdYWXbEehq,TM(^^Y2j%a+ZB_rR#<_C.4#B');
define('SECURE_AUTH_KEY',  'NntpzzU VR9@G_3OI$fP+-UF6YmHU; ?%JKt-v=VYz)F`Rx.ncNUoV20jOUz%~/O');
define('LOGGED_IN_KEY',    '7<GKobem<5 xPc1(VJm-98|s|(s.+xbrv^M3s&a!_(GP#R()R<Cbp1c>~KN~I,Y,');
define('NONCE_KEY',        '/+I+gH4ll(:E.l#%pN:n(lRU8=W_jyr;vRIN+jqB{XwLP<#Q.l-jN|]` >oc@G$K');
define('AUTH_SALT',        'S^v19^?DQsE-b3443]:n;5<|[c8;t/E6*H]?LLYN2d3PzZj*>@_nZbC|R.R!_>Bb');
define('SECURE_AUTH_SALT', 'KQ4u5t QJ^+O4,zLH/Ek}C]+*<I^cp^ft^zFIyhM40`#m|L]Qi:p@5d.^?]--#<}');
define('LOGGED_IN_SALT',   '}QRz@U$EHd|6ncj+Uh9e_;SQG8W-=^j!4;^+N BV_tmf##cM~<7Fo|/Cl?t`jL{~');
define('NONCE_SALT',       ']cAkRNFpT]RC/ *^nmQT*V#k!+w/Z+m1G}pi&T6ZwcjWn)]/Q29x+e@#4gvk0)D@');


/* Absolute path to the WordPress directory. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/* Sets up WordPress vars and included files. */
require_once(ABSPATH . 'wp-settings.php');