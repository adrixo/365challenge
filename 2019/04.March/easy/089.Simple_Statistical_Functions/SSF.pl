#!/usr/bin/perl

use Math::Complex;

sub meanValue {
  my @dataArray = @_;
  my $total = 0;
  foreach $number (@dataArray){
    $total += $number;
  }
  return $total/ @dataArray;
}

# +(mean-value)² / |elements|
sub varianceValue {
  my ($refArray, $mean) = @_;
  my @dataArray = @{$refArray};
  my $total;

  foreach $number (@dataArray){
    $total += ($number - $mean)**2 ;
  }

  return $total/ @dataArray;
}

sub standardDeviation {

  my $variance = shift;

  print("Calculating deviation of variance $variance\n");

  return sqrt($variance);

}

my $line;
my @numbers;
my $number;
my $i = 0;

print("Type <end> to finish. \n");
do {
  $i++;
  print("Enter number $i: ");
  $line = <STDIN>;
  chomp $line;
  $number = sprintf("%.2f", $line);
  if($line ne "end" && $line ne "") { push @numbers, $number;}
} while($line ne "end");

if (@numbers == 0) {
  print("A number must be entered. \n");
  exit();
}

print("The list of numbers is: \n [");
foreach $number (@numbers) {
  print("$number, ");
}
print("]\n\n");

my $mean = meanValue(@numbers);
my $variance = varianceValue(\@numbers, $mean);
my $standarDeviation = standardDeviation($variance);

print("Mean value: $mean\t Variance: $variance\t standarDeviation: $standarDeviation\n");
