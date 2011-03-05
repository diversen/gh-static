<?php


function gh_static_generate (){
    $static_dir = mainCli::$ini['gh-static']['gh_static_site_dir'];
    $url = mainCli::$ini['gh-static']['gh_static_index_url'];
    $command = "wget -m -k -K -E  $url";
    cos_exec($command);
    $command = "cp -rf ./$url/* $static_dir";
    cos_exec($command);
}

function gh_static_push (){
    $static_dir = mainCli::$ini['gh-static']['gh_static_site_dir'];
    echo $command = "cd $static_dir && git add . && git commit -m \"auto-commit\" && git push";
    cos_exec($command);
    //$command = "rm -rf ./$url";
    //cos_exec($command);
}

mainCli::setCommand('gh-static', array(
    'description' => 'Sane check to see if hosts specified in config are alive',
));

mainCli::setOption('gh_static_generate', array(
    'long_name'   => '--generate',
    'description' => 'Will generate the static site into location specified in .ini file',
    'action'      => 'StoreTrue'
));

mainCli::setOption('gh_static_push', array(
    'long_name'   => '--push',
    'description' => 'Will push the static site to git url specified in .ini file',
    'action'      => 'StoreTrue'
));
