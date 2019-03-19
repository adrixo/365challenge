#!/usr/bin/env perl

use strict;
use warnings 'all';

open my $fh, '<', $ARGV[0] or die "Error: $!";
while (<STDIN>) {
    while(my $bw = <$fh>) {
        $bw =~ s/^\s+|\s+$//g;
        s/$bw/'*' x length($bw)/ge;
    }
    print;
}
close $fh;
