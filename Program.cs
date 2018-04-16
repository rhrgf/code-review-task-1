using System;
using System.Collections.Generic;
using System.Linq;

namespace csharptest
{				
    class Words 			//用于存放单个单词的内容及数量
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
                                //文件读取

            string[] ss = text.Split(' ');	//以空格分割整个句子为单个单词

            //list
            List<string> wordsList = ss.ToList().Distinct().ToList();		//Distinct方法用于找出不同种类的单词，然后将其构建为list作为比较的参考

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
            query = from items in newList orderby items.num descending select items;		//以出现频率降序排列
            foreach (var item in query)
            {
                Console.WriteLine(item.content + " " + item.num);
            }

            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }
    }
}
