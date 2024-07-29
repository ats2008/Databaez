/**
 * id, first_name, second_name, country, email, fruit
 *
 * first_name x second_name x country x email{first_name.second_name x domain} + fruit
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string filename{"data.csv"};
    std::fstream file{filename, file.in | file.out};
    long count_rw = 1;
    long count_fn = 0;
    long count_sn = 0;
    long count_cty = 0;
    long count_eid = 0;
    long count_ff = 0;

    std::vector<std::string> first_name{"Astrid", "Kaius", "Luna", "Maverick", "Sage", "Piper", "Rowan", "Indigo", "Journey", "Caspian", "Lyra", "Atticus", "Remi", "Marlowe", "Vesper", "Orion", "Lila", "Beckett", "Odessa", "August", "Wren", "Cohen", "Magnolia", "Ezra", "Clio", "Gideon", "Lyric", "Thatcher", "Sapphire", "Mariana", "Asher", "Viva", "Casandra", "Jenson", "Lylah", "Bronson", "Nadia", "Sawyer", "Zara", "Felix", "Tatum", "Kaida", "Roderick", "Imogen", "Gage", "Marigold", "Casper", "Ophelia", "Jagger", "Lyndon", "Piperine", "Thaddeus", "Cressida", "Sageant", "Journeyne", "Caspiana", "Lyriquella", "Atticusa", "Remianna", "Marlowena", "Vesperina", "Orionna", "Lilauna", "Becketta", "Odessaa", "Augustina", "Wrennabella", "Cohenita", "Magnoliana", "Ezralla", "Clioanna", "Gideona", "Lyriquela", "Thatcherine", "Sapphirinea", "Marianella", "Asherina", "Vivala", "Casandrina", "Jensonna", "Lylaha", "Bronsonia", "Nadiauna", "Sawyerra", "Zaraela", "Felixina", "Tatuma", "Kaidala", "Rodericka", "Imogena", "Gageana", "Marigolda", "Caspiana", "Opheliauna", "Jaggerita", "Lyndona", "Piperineela", "Thaddaeusia", "Cressidala", "Sageantina", "Akira", "Yuna", "Leela", "Rina", "Kaito", "Minju", "Jiaqi", "Arjun", "Lian", "Sora", "Hana", "Rohan", "Yiming", "Lingling", "Akshay", "Meiying", "Ryohei", "Minna", "Jatin", "Xiaoyu", "Hiroto", "Yujin", "Aditya", "Miko", "Soo-jung", "Anshul", "Zihan", "Rieko", "Hyeon-ji", "Vinit", "Jingwen", "Kenzo", "Da-hyun", "Shubham", "Xiaohua", "Yuto", "Min-gi", "Aarav", "Qianyu", "Koki", "So-young", "Rohini", "Xueling", "Taro", "Yoon-ji", "Ayush", "Ziyang", "Ryota", "Min-hee", "Shruti", "Xinran", "Hiroki", "Ye-seul", "Aditya", "Qianqian", "Kaitlyn", "So-hyun", "Arun", "Xinyi", "Tetsuya", "Yoon-ah", "Aryan", "Zixuan", "Ryusei", "Min-ji", "Swati", "Xiangyu", "Kojiro", "Soo-jin", "Abhay", "Qiuyu", "Hiroshi", "Yuna", "Rohan", "Xueling", "Takashi", "Min-kyung", "Ananya", "Ziyue", "Ryota", "So-young", "Akshay", "Xinran", "Hiroto", "Yoon-ji", "Shruti", "Xinyi", "Kaito", "Min-hee", "Aarav", "Qianqian", "Taro", "So-hyun", "Arun", "Xinran", "Ryusei", "Yoon-ah", "Aryan", "Zixuan", "Kojiro"};

    std::vector<std::string> second_name{"Brooks", "Rylan", "Vynne", "Flynn", "Loxley", "Wilder", "Ryder", "Stone", "Ridge", "Banks", "Sawyer", "Greyson", "Justice", "Maverick", "Rowen", "Holden", "Jenson", "Reed", "Slade", "Garrison", "Thatcher", "Wildwood", "Branson", "Caswell", "Durante", "Estes", "Fothergill", "Gresham", "Huxley", "Ingram", "Jagger", "Kipling", "Langford", "Marlowe", "Nettle", "Oakes", "Pembleton", "Quinlan", "Ravenwood", "Slaney", "Tallon", "Upton", "Varden", "Waverly", "Xanthe", "Yates", "Zarek", "Bridger", "Carmichael", "Davenport", "Easton", "Fenton", "Gage", "Haddon", "Ivor", "Jervis", "Kier", "Larkin", "Mansfield", "Norwood", "O'Connor", "Pritchard", "Quiggly", "Ransom", "Selden", "Telford", "Upton", "Vallance", "Wainwright", "Xanthus", "Yardley", "Zebulon", "Bronson", "Carver", "Dillingham", "Eastwick", "Fothergill", "Gower", "Haverford", "Inglewood", "Jocelyn", "Kester", "Loxton", "Mansell", "Nethercoat", "Orlan", "Pearsall", "Quinby", "Rothery", "Segrave", "Tallantyre", "Ufton", "Valliere", "Waverley", "Xylia", "Yardsworth", "Zarela", "Bronwyn", "Carwyn", "Dylana", "Nakamura", "Kimchi", "Desai", "Liang", "Tanaka", "Park", "Patel", "Wang", "Matsumoto", "Lee", "Jain", "Chen", "Saito", "Kwon", "Mittal", "Zhang", "Morioka", "Yoon", "Rao", "Liu", "Taniguchi", "Kim", "Agarwal", "Huang", "Nakahara", "Cho", "Mehta", "Xu", "Matsumoto", "Park", "Kapur", "Li", "Kato", "Lee", "Thakkar", "Zhang", "Takahashi", "Kim", "Patel", "He", "Mori", "Yoon", "Goyal", "Chen", "Sasaki", "Kwon", "Jain", "Liu", "Nakamura", "Lee", "Agarwal", "Xu", "Tanaka", "Park", "Desai", "Liang", "Matsumoto", "Kimchi", "Mittal", "Wang", "Saito", "Kwon", "Rao", "Zhang", "Morioka", "Yoon", "Agarwal", "Liu", "Nakahara", "Cho", "Mehta", "Xu", "Matsumoto", "Park", "Kapur", "Li", "Kato", "Lee", "Thakkar", "Zhang", "Takahashi", "Kim", "Patel", "He", "Mori", "Yoon", "Goyal", "Chen", "Sasaki", "Kwon", "Jain", "Liu", "Nakamura", "Lee", "Agarwal", "Xu", "Tanaka", "Park", "Desai", "Liang"};

    std::vector<std::string> country{"Afghanistan", "Armenia", "Azerbaijan", "Bangladesh", "Bhutan", "Brunei", "Cambodia", "China", "East Timor", "Georgia", "India", "Indonesia", "Iran", "Israel", "Japan", "Jordan", "Kazakhstan", "North Korea", "South Korea", "Kuwait", "Kyrgyzstan", "Laos", "Lebanon", "Malaysia", "Maldives", "Mongolia", "Myanmar", "Nepal", "Oman", "Pakistan", "Albania", "Austria", "Belgium", "Bulgaria", "Croatia", "Cyprus", "Czech Republic", "Denmark", "Estonia", "Finland", "France", "Germany", "Greece", "Hungary", "Ireland", "Italy", "Latvia", "Lithuania", "Malta", "Netherlands", "United States of America", "Canada", "Antigua and Barbuda", "Bahamas", "Belize", "Canada", "Costa Rica", "Cuba", "Dominican Republic", "El Salvador", "Guatemala", "Mexico"};

    std::vector<std::string> email_domain{"@gmail.com", "@yahoo.com", "@outlook.com", "@smail.com", "@protonmail.com", "@uni.edu"};

    std::vector<std::string> fav_fruits{"Apple", "Banana", "Mango", "Orange", "Watermelon", "Grapes", "Strawberry", "Pineapple", "Peach", "Cherry", "Plum", "Kiwi", "Lemon", "Lime", "Grapefruit", "Avocado", "Papaya", "Pomegranate", "Acai berry", "Blueberry", "Raspberry", "Blackberry", "Elderberry", "Cranberry", "Gooseberry", "Boysenberry", "Loganberry", "Rambutan", "Mangosteen", "Dragon Fruit", "Starfruit", "Kiwano", "Tamarillo", "Physalis", "Guanabana", "Ackee", "Soursop", "Feijoa", "Cupuacu", "Tangelo", "Clementine", "Satsuma", "Meyer lemon", "Kumquat", "Loquat", "Persimmon", "Quince", "Pummelo", "Sour orange", "Yuzu", "Blood orange", "Cara cara navel", "Honeydew melon", "Casaba melon", "Charentais melon", "Canary melon", "Rockmelon", "Horned melon", "Tangelo", "Ugli fruit", "Pomelo", "Sugar apple", "Cherimoya", "Anona", "Guava", "Passionfruit", "Pulasan", "Rambutan", "Lychee", "Longan", "Tamarind", "Amla", "Star anise", "Jujube", "Persimmon", "Medlar", "Rowal", "Elder", "Rowan", "Bilberry", "Huckleberry", "Cranberry", "Blue elder", "Red currant", "Black currant", "Gooseberry", "Elderberry", "Tayberry", "Cloudberry", "Crowberry", "Bilberry", "Whortleberry", "Haskap berry", "Salal berry", "Buffalo berry", "Chokecherry", "Juneberry", "Serviceberry", "Akebia", "Yubari king melon"};

    const long len_fn = first_name.size();
    const long len_sn = second_name.size();
    const long len_cty = country.size();
    const long len_eid = email_domain.size();
    const long len_ff = fav_fruits.size() - 1;

    if (!file.is_open()) {
        std::cout << "failed\n";
        return 0;
    }

    file << "id, " << "first name, " << "second name, " << "country, " << "email, " << "favorite fruit\n";
    while (count_fn < len_fn) {
        count_sn = 0;
        while (count_sn < len_sn) {
            count_cty = 0;
            while (count_cty < len_cty) {
                count_eid = 0;
                while (count_eid < len_eid) {
                    file << count_rw << ", " << first_name[count_fn] << ", " << second_name[count_sn] << ", " << country[count_cty] << ", " << (first_name[count_fn] + "." + second_name[count_sn] + email_domain[count_eid]) << ", " << fav_fruits[count_ff] << '\n';
                    ++count_eid;
                    ++count_ff;
                    ++count_rw;
                    if (count_ff > len_ff)
                        count_ff = 0;
                }
                ++count_cty;
            }
            ++count_sn;
        }
        ++count_fn;
    }

    file.close();
}
