#!/usr/bin/perl
use Scalar::Util qw(looks_like_number);


my $input;
my @ANS;
my @operators = ("+","-", "*", "/");
my $result=0;

do{
	$input = readline(STDIN);
	chomp($input);

	if($input eq '+'){
			foreach my $n (@ANS){
				$result = $result + $n;
			};
			@ANS = ($result) ;
		}

		if($input eq '-'){
			foreach my $n (@ANS){
				$result = $result - $n;
			}
			@ANS = ($result);
		}

		if($input eq '/'){
			my $i = 0;
			foreach my $n (@ANS){
				if($i == 0)
					{
						$result = $n;
						$i = 1;
					}
				else {
					$result = $result / $n;
				}
			}
			@ANS = ($result);
		}

		if($input eq '*'){
			$result = 1;
			foreach my $n (@ANS){
				$result = $result * $n;
			}
			@ANS = ($result);
		}

		if(looks_like_number($input)){
			push @ANS, $input;
		}

	$result=0;

	print("[$input] @ANS\n")
} while($input ne "x" );
