import System.Random
import System.Random.Shuffle


main = do bads <- readFile "badwords.txt"
          let badwords = map (filter (/= '\r')) . lines $ bads
          rgen <- newStdGen
          let dicts = map ((shuffle' badwords (length badwords)) . mkStdGen) $ randoms rgen
          interact $ uncensor dicts
          putStr "\n"

uncensor dicts = unwords . map updateWord . zip dicts . words

updateWord (dict , w) = if censored w
                           then let (pre , oldWord , post) = censoredWordPart w
                                    newWord = findRealWord dict oldWord
                                 in pre ++ newWord ++ post
                           else w

censored str = '*' `elem` str

censoredWordPart str = let (prefix , rest) = span (/= '*') str
                           (stars , postfix) = span (== '*') rest
                        in (init prefix , last prefix:stars , postfix)

findRealWord dict word = head $ filter (\xs -> head word == head xs && length word == length xs) dict
