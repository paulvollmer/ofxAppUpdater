<?php
  $feed_contents = file_get_contents('https://raw.github.com/'.$HTTP_GET_VARS[url]);
  header('Content-Type: application/rss+xml');
  echo $feed_contents;
?>