
Enumerable.Range(1980, 7).ToList().ForEach( x => Console.Write((x.ToString().Distinct().Count() == 4) ? x.ToString() + Environment.NewLine : ""));
