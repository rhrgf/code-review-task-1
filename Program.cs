using System;
using System.Collections.Generic;
using System.Linq;

namespace csharptest
{
    class Words
    {
        public string content;
        public int num;
    }

    class ReadFromFile
    {
        static void Main()
        {
            string text = System.IO.File.ReadAllText
                                (@"/Users/MedillEast/Documents/Project/Test/c#test/csharptest/csharptest/words.txt");

            string[] ss = text.Split(' ');

            //字典方便计数但不方便排序
            //Dictionary<string, int> wordStatus = new Dictionary<string, int>();
            //foreach (var word in ss)
            //{
            //    if (wordStatus.ContainsKey(word))
            //        wordStatus[word]++;
            //    else
            //        wordStatus.Add(word, 1);
            //}

            //foreach (var kvp in wordStatus)
            //{
            //    Console.WriteLine(kvp.Key.ToString() + " " + kvp.Value.ToString() + "\n");
            //}

            //list
            List<string> wordsList = ss.ToList().Distinct().ToList();

            int alreadyHave = wordsList.Count;
            int[] wordsNum = new int[wordsList.Count];
            for (int i = 0; i < ss.Length;i++)
            {
                for (int j = 0; j < alreadyHave; j++)
                {
                    if (ss[i].Equals(wordsList[j]))
                    {
                        wordsNum[j] += 1;
                    }
                }
            }

            List<Words> newList = new List<Words>();
            for (int i = 0; i < wordsList.Count; i++)
            {
                newList.Add(new Words() { content = wordsList[i], num = wordsNum[i] });
            }
            IEnumerable<Words> query = null;
            query = from items in newList orderby items.num descending select items;
            foreach (var item in query)
            {
                Console.WriteLine(item.content + " " + item.num);
            }

            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }
    }
}
