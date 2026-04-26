<?php

define('WP_HOME', 'https://hounejja.42.fr');
define('WP_SITEURL', 'https://hounejja.42.fr');


define('DB_NAME', getenv('WORDPRESS_DB_NAME') );
define('DB_USER', getenv('WORDPRESS_USER') );
define('DB_PASSWORD', trim(file_get_contents('/run/secrets/db_password')) );
define('DB_HOST', getenv('WORDPRES_DB_HOST') );
?>
