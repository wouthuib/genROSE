#!/usr/bin/perl
use strict;
use warnings;
use threads;
 
my (@exes,$nr,%threads,%subs);
 
push @exes, 'Binary/LoginServer.exe loginserver.conf';
push @exes, 'Binary/CharServer.exe charserver.conf';
push @exes, 'Binary/WorldServer.exe worldserver.conf';
 
foreach my $exe (@exes) {
    $nr++;
    my ($dir,$file) = ('.',$exe);
    if ($file =~ /\//) {
        ($file,$dir) = split(/\//,reverse($exe),2);
        $file = reverse($file);
        $dir = reverse($dir);
    }
    $subs{$nr} = sub {
        chdir($dir);
        while (1) {
            system($file);
            sleep 3;
        }
    };
    $threads{$nr} = threads->new(\&{$subs{$nr}});
    sleep 1;
}
sleep;
 

