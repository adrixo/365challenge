#!/usr/bin/perl
use strict;
use warnings;
use 5.010;
no warnings 'experimental';

my $option = 0;
my @hour;
my $strHour;

print "This is the sleep cycle calculator. \nIf you enter a sleep time or a wake-up tame a range of possible dates will be generated.\n";

while ( $option >= 0 && $option <= 2 ){
  print "Do you want to input a sleep time (1) or wake-up time(2) ?: ";
  $option = <STDIN>;
  chomp $option;

  if($option >= 0 && $option <= 2){
    print "\n\nEnter an hour (HH:MM): ";
    $strHour = <STDIN>;
    chomp $strHour;
    @hour = split(/:/, $strHour);
  }
  
  given ($option) {
    when ($_ == 1) {
      wakeUpTimes(@hour);
    }
    when ($_ == 2) {
      sleepTimes(@hour);
    }
    default {
      print "Option not valid. Exiting...\n";
    }
  }
}

#given a sleeptime prints the wake up possibles hours
sub wakeUpTimes {
  my @sleepTime = @_;
  my $cycle = 0;
  my $carry = 0;

  print "\nIf your sleep time is: $sleepTime[0] : $sleepTime[1]\n";
  while($cycle < 650){ #more than 10 hours sleeping
    $cycle += 90;

    $sleepTime[1] += 30;
    if ( $sleepTime[1] >= 60){
      $carry = 1;
      $sleepTime[1] -= 60;
    }

    $sleepTime[0] += 1 + $carry;
    if ( $sleepTime[0] >= 24){
      $sleepTime[0] -= 24;
    }

    $carry = 0;
    printf("A possible wake-up hour will be: $sleepTime[0]:$sleepTime[1] (%s h sleeping)\n", $cycle/60);
  }
}

#given a wakeUpTimes prints the $sleepTime possibles hours
sub sleepTimes {
  my @wakeUpTimes = @_;
  my $cycle = 0;
  my $carry = 0;

  print "\nIf your sleep time is: $wakeUpTimes[0] : $wakeUpTimes[1]\n";
  while($cycle < 650){ #more than 10 hours sleeping
    $cycle += 90;

    $wakeUpTimes[1] -= 30;
    if ( $wakeUpTimes[1] < 0){
      $carry = 1;
      $wakeUpTimes[1] += 60;
    }

    $wakeUpTimes[0] -= 1 + $carry;
    if ( $wakeUpTimes[0] < 0){
      $wakeUpTimes[0] += 24;
    }

    $carry = 0;
    printf("A possible wake-up hour will be: $wakeUpTimes[0]:$wakeUpTimes[1] (%s h sleeping)\n", $cycle/60);
  }
  print "\n"
}
