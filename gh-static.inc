<?php

/**
 * This is function which genrates the static site.
 */
function gh_static_generate (){

    // ini settings will be found in the static var mainClin::$ini
    $static_dir = config::getModuleIni('gh_static_site_dir');

    // The url to index (mygithub)
    $url = config::getModuleIni('gh_static_index_url');

    // create dir where files will be put
    if (!file_exists($static_dir)) {
        $command = "mkdir $static_dir";
        cos_exec($command);
    }
    
    // wget command
    $command = "wget -m -k -K -E  $url";
    
    // execute
    cos_exec($command);

    // copy the content of the url to the static dir
    // (/home/dennis/www/diversen.github.com)
    //$command = "mkdir $static_dir";
    
    
    $command = "cp -rf ./$url/* $static_dir";

    // execute
    system($command);
}

/**
 * next command is the push command.
 */
function gh_static_push (){

    // the static dir where we will push from
    $static_dir = config::getModuleIni('gh_static_site_dir');

    // cd into dir add - commit - push
    $command = "cd $static_dir && git add . && git commit -m \"auto-commit\" && git push";
    
    // execute
    cos_exec($command);
}


// enable commands in shell - first we set a base command
mainCli::setCommand('gh-static', array(
    'description' => 'Command to generate a static site from a dynamic',
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