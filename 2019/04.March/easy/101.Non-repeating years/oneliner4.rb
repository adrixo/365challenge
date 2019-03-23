# oneliner4.rb

(x..y).each do |number|
	puts number unless number.to_s.squeeze != number.to_s
end
