<?php

/**
 * This is function which genrates the static site.
 */
function gh_static_generate (){

    // ini settings will be found in the static var mainClin::$ini
    $static_dir = mainCli::$ini['gh-static']['gh_static_site_dir'];

    // The url to index (mygithub)
    $url = mainCli::$ini['gh-static']['gh_static_index_url'];

    // wget command
    $command = "wget -m -k -K -E  $url";
    
    // execute
    cos_exec($command);

    // copy the content of the url to the static dir
    // (/home/dennis/www/diversen.github.com)
    $command = "cp -rf ./$url/* $static_dir";

    // execute
    cos_exec($command);
}

/**
 * next command is the push command.
 */
function gh_static_push (){

    // the static dir where we will push from
    $static_dir = mainCli::$ini['gh-static']['gh_static_site_dir'];

    // cd into dir add - commit - push
    $command = "cd $static_dir && git add . && git commit -m \"auto-commit\" && git push";
    
    // execute
    cos_exec($command);
}


// enable commands in shell - first we set a base command
mainCli::setCommand('gh-static', array(
    'description' => 'Sane check to see if hosts specified in config are alive',
));

// then we set a option
mainCli::setOption('gh_static_generate', array(
    'long_name'   => '--generate',
    'description' => 'Will generate the static site into location specified in .ini file',
    'action'      => 'StoreTrue'
));

// and another option
mainCli::setOption('gh_static_push', array(
    'long_name'   => '--push',
    'description' => 'Will push the static site to git url specified in .ini file',
    'action'      => 'StoreTrue'
));