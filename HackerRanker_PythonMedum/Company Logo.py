#!/usr/bin/env python
# coding: utf-8

# ## Company Logo
# 
# A newly opened multinational brand has decided to base their company logo on the three most common characters in the company name. They are now trying out various combinations of company names and logos based on this condition. Given a string **s**, which is the company name in lowercase letters, your task is to find the top three most common characters in the string.
# 
# * Print the three most common characters along with their occurrence count.
# 
# * Sort in descending order of occurrence count.
# 
# * If the occurrence count is the same, sort the characters in alphabetical order.
# 
# For example, according to the conditions described above,
# 
# **GOOGLE** would have it's logo with the letters **G**, **O**, **E**.
# 
# ### Input Format
# 
# A single line of input containing the string, **S**.
# 
# ### Constraints
# 
# * **3 < len(S) <= 10^4**
# 
# * **S** has at least **3** distinct characters
# 
# ### Output Format
# 
# Print the three most common characters along with their occurrence count each on a separate line.
# 
# Sort output in descending order of occurrence count.
# 
# If the occurrence count is the same, sort the characters in alphabetical order.
# 
# ### Sample Input 0
# 
# aabbbccde
# 
# ### Sample Output 0
# 
# b 3
# 
# a 2
# 
# c 2
# 
# ### Explanation 0
# 
# 
# **aabbbccde**
# 
# Here, b occurs **3** times. It is printed first.
# Both a and c occur **2** times. So, a is printed in the second line and c in the third line because a comes before c in the alphabet.
# 
# **Note**: The string **S** has at least **3** distinct characters.

# In[1]:


def logo_count(N, A):
    
    aList = list(A)
    aDict = dict()
    sDict = dict()
    fDict = dict()
    vList = []
    vSetL = []
    sList = []
    
    for ai in aList:
        aDict[ai] = aDict.get(ai, 0) + 1
        
    saList = sorted(aDict.items(), key=lambda x:x[1], reverse=True)
    #print(saList)
    
    for sa in saList:
        vList.append(sa[1])
        
    vSetL = sorted(list(set(vList)), reverse=True)
    #print(vSetL)
        
    for sa in saList:
        sDict.setdefault(sa[1], []).append(sa[0])
    #print(sDict)
        
    for k, v in sDict.items():
        if len(sDict[k]) > 1:
            #print('debugging:', sorted(sDict[k]))
            for vi in sorted(sDict[k]):
                fDict[vi] = k
        else:
            fDict[v[0]] = k
    #print(fDict)
    sList = sorted(fDict.items(), key=lambda x:x[1], reverse=True)[:N]   
            
    return sList[:3]


# In[2]:


N = 3
A = "aabbbccde"
print(logo_count(N, A))


# b 3
# 
# a 2
# 
# c 2

# In[3]:


N = 3
A = "qwertyuiopasdfghjklzxcvbnm"
print(logo_count(N, A))


# a 1
# 
# b 1
# 
# c 1

# In[4]:


N = 3
A = "kwuzazrxreqpypvzdsnvtumobemekfskfshopevggqgoascrunynwaxolxcygnkllnqslcqrlmlbvrarepmfkdbacawcipzpbcgnekzbrhotracywrlarfawxogygnanyhtgtvdfnaluefebhjivqagvcljghgbscvkmmtnafamqffycsgufjugqzhgstmjhwzosrnveqnwahflysxumwuvxyxrmarwzbabufxajdqybetjtucqhnavugflaofmtrkkrbsszoqcvuhydsdlfwinucgtlgeejaftfyaidcklgfgkwwgjlnbwryvoqbzzbktemvhpuudgfgxwzcmwgvcnofdebcwyhxmnxefrkdlafvfwgrzembfugqxcpukvgoixedbyqjmfywqqwnhotqdpgdailabictebdgnjfdbiqbnlrbsduwebtqaevukkyheypwdksmpztideoropeepphoniddgnrsmiqsafuyxvqerkoitpqsgswtroiwralcrupfavyyfwmyzuocaeyriavmvukqhzjzubnnrecsqbjngtczuonyktdcdvukxcdcwatlvjluumjijdfemilyarwvdytraygahbpgarwyzffyoukgmdgemmmxkajwsqtkpaarjskvuldfvlydkcoezgygjfygwzwsndfmkxzuljsnnltlpnjrtkrvdzchhmaejmiatzvmyysdiqhhyihmavkcjfuauvtwafnqyowyfsnfmxxvomarjvplrqfopknlstgnnodifdiqzvliszptdcjcffzbacszftbkeorbftaqjpfaackqqobbaccwzxwbymkwckgzkoqmwiilsgitbqbfjzwkzodaqgknmxujfrdgoiupvqmnpkruxwungbfjbcpqsxizuvbpedajxkncbcunlrkwiokezfdgkdwiiukwcktftfzzslnsojtpjwziiuyiutkhxpasblitpjlxerdvhwgtpddgqfyuyzesiccvgkwyfwohoupwmrolfklonyqzjlqeudamffigrlzaevwbccenojadkxeimomlfhqvhtayvzlmvvutnqvewqhjsqilimessmlvrrbvyvkpgahvqrexhnxptxyokzorxxiwozvmsjabeqrygljcvjfksvnsnoocnwgwuelucefyjtpdndaehggveotcbieawteoafihpxixkfvxezknxtnyzwgdwzsiiodlmokthekehtzgwtglnsajikalneolwjddizaoslvxxbrejwngjmafwprmhvqtoiekdfgputwwcmcgzbnhzrprenikdtgcsvzzkzcfgqyrvhommotehbulrnhmdgttbctmoxxwosvypmdxeqczvxrytubvdsdyybocipfmxlplhkfiejtdfrgukhqtdzressilhdxmqrortqkcuxjrnttsmsoeygboztakfpbbrxfzsdzzdluzqsdqmwspctlsacrlevxydoyvjkzorizimrdzrmzbjtrsqijsldyhpslluxtuiywkjfhhebndzkmbtkboiuzhdcwgypqjwqapzvwborqekdwqytpzcgxwxgnxemonwlescunaseuyokpwotnqcyvjjhylcaxlhpulxxijljfhflzadncbjdqwosbgicdyjbuelpjztutufujhxdnzkbwtzienxmcbxtfhifepbocycnemphavdsdylzfvziznrtfsshcnbfcsykegqokinhqblbcsrmxcwhwwjvukfyxhpeoqqotornsomdwboiymvzjunlbnivptahxcfftqmcxbxavsuicxxezjklcqbyujckxojyjxacnvdptvwuzguwhbpoajmdrrqxoiubxnjwjfqhzrcsbzdsaxzinqjhknjnjxuwlnpzbwrbrttohdmltxdqesavkhbawwuyzgzbdmrltobnyuxcvlmcmncziwbtzissojcyzfuhbbxdrahjlkjktuzsphcfmgkleschnqjdeovjqyysbgdeuvulzfsfjygezmeowwpwshrbqyfegkarkxpdztxkfcdhncaqjbbnvwzhcxmqxfdazrtiektdepseomsmqcnbiwwgtvzgxkypieeoojpazahbcgiircwydmusmudncuplrbrlsihqwomvipoexwazsdtggvwfscaippzctttuofgdipmiqicreumjscueevvuvcubiiikhzmcgndjeisraarrmjolyahddukyfowxarkmcdrwabcvcsfvsphozszbobxhzaymnwfzfwswrgqlwlstxihdajvnhvlzzdbqxuiigdgsmitsiirfiqkfcsnplwfprsbhtvukbvuukwaodwcqeaapeyixybuxijhohglzlyvoegyjovolmcxtxwukswhewucpbhaeiyqwspqiyobmtivnjawfxayibgadadygbvdcvioxnpecpnvivqxiqpeywiwgzicqzdxlaijsnhxboigwmetyknaxxhlbcznwcypeyjzyvhvemaycydcixelpkxhovqqziyvbjuyykmsxidubxvzvbycnkowbddqltpxzsdwyfivjqsnndtqokshbecnirxxwqhwthrzfadkdzlorwcwkfvmkglxhaiiexjeobyvtizjgsnzcdiwutvhotgyycurkibbkmjbeljdtldhpaysaufjacdapssronnvxkvydbehxmvmfhmudemmnfrlfvhwzdcdqywcnjucjyljjgdznrayqsfxvhfaznnnqblaqvflrrvrpujemcglqtyndqwapfytxpnrhdtumifokqeovtbyszckviprgidsvzbswhkaocjspubisoweoaxmuiynybqszarslsrfbsvbodzuetztqifpwtwvkfgtynzfcrzovnthwobbsbbhgtzteqpsglchkevhjgecwlmhaglaionpkhpfevbmrltntiesahjaafokkyxvtxkxnezyavmabjhxhxdklmjdyfejbpqudaoinfjwzbvvmjyjnyflsohuhadnthxptlnktqknwvbwsfvlrwkjkoboqqpljvsxjpxcfqfsrivbtnyjxgklbjjhzfiodlgjxcvotafmhshglrfdraxzbeqpmddslioeecfsqurfryltwzlqellpqvjizdfndcqtkuzoaagzwnkdmzixgpndrlmqbmjvmoxvmuypsxhtigvwfncashqqjfcmculsnoswegmepizuugkvbvjmiwztrdzhbzhqumeiswsdouiawftqjclzxfgjzrjrrlkknmddyjxlauppaewdlfwekpfslxweuhfuyiltsoyfgnxtdhhvyjkdqayzcmpbgrmpptawhxpsijutzhacvubjntlzmrryaesogojbikcuuuaiyombqyujwxrbggiringxommmtsawjcykdhfetggfjaihbrrfvmwzcspbdxtifgxcpcqmuodtdpwqumiyoquurcpguzjucccndqqzzlvempkvjiwtjnhveyraczjuxzfkzftnfmvydgsxfwmkgolqoinpklcjplrbxyoliciybnudvxxloqtngamrlrdxolplcwqftjovtbdnmxnksjvoosggjfvslagnzadawbanudghbpezkirtnwgueeowrbnkbdtqsoynpftpofmjdtrhpymfnnwtnhepjksoyfdtdwhydutnbsgkgigyhgtbryruktazneowripzvgpnzdxhfjcqflsdpjhabzjoxjeigguhkjfmzypduakqyajxqfygeygeyyltlyeygpkqfeolmwoocajrkcvqztnzkdpsqtcfedghhesobhxjjnhroorydhagwllqpugrxwhfxhhuqozniqunjxbngdottuawzkhkqaumqononncyzzwfqguswpjmnjnnyytbznoxsmfsnlbszraxmlljgmnhmetowcbperxjjaebvaljjjxhvqnlcfqyzzvfywhkjnvufmtaexhpwiclpwlwepzzfclfcftqcbbmzpxhksiurcjlgkyufwaxfqfqsqochugxqsgrmzghbwnbskmuiawozuodaaoihapopqxvzhxitwdtojgxmkkqbmuljafddtqohszckinrcaeghhlsvaoosbwszgrckdcfkzuynvagavdmdbjaqngfyhozkkqqlwhiitelcbvpircblhmwhrqjbsqtgxmjtmojsorlxvrhehsqkxjuqpylpngiacfmflgabkhxtiowwvjlsjmufqmsgnosddyxohrztrxbbdjhhiaucqygywihlfejnoxqtxdhxdtndixjnwaxhdefuqcfbepmmgcdenvgoeyrvtoeaydrgbiqzwequcmoyghldhgmeplmdsskrkueaamlrjklfldhushjmjjqdpharwkicfuazwamjuozvgtytzctmnkfifldetfrsxrznocrebqkuaqnrixmcvnidujcvgwgsowrpasnyzdbwpmdirjhlrsdlnavtgzcubhkjinuxphopmvtsfkazrgdfumjydhehxkdlvwtjikhidytcxpppnthckdjecqfroujholphmjsupxfdcrhjnyrcblqjoqftkbgdrjbijzlqpvzwmglqvtaxucfzucfmjiaqnujxbojcahgouewwiddbblzebzrwjxmdtbkgdfywwxwnymaxlpurujvabouoqgzgbjujpqrghragulhvdcjvlpctvcaytmjznewglyipuwlupfswzbwmommlrrbzrlmuyhgvpfqrdrzkzeykfmywaehsdqflljvvpwkxpksqjkdcwroukoselfugujtstrllayabeumkyxgvlglkyeyqxtdfwgvdbuhnwvcmuznwcpocrqptjhrspmdeygbvuropxcpiimtlliyyfhzabhycohvwimdvpxkhhktyfshzwfvjmbwqmgnasfqcjtgzhuufxrreqxrvcwzfojohdlwnbwcwzckcekwmwmfgcuyhfamigyndjllfbhyesnaceglwlojgywrfobvxswmhkvjqeargkkrcmyklxfcgmdutitedwkubaaasnywflzvzuqjuubyrdrbletdwvwlivjfiqiedisurfnowcruvygmmayamwucbjafhsvejhfmmtellyxwsqowrgiapxdhxrkxtqcwmusttwblhutfrungizwalkukfctpvfbzlqmryxblsawclrjggyuatagymrvkzildltdbbcfyuehonedcnbuwlklcoqvmqmkxzjagmjjrgdquhvmgsyetgtohtuqqjmimyuzpcxxynmaafycqijpqndqzxhpokrvhfgqkxbjbhksuahjgvrqzmihwsqoijjkyqiyrmaybxpxcyacwmkcypkctfuyrriluytxvprrltvzsvxahrrxvjfvevibxibobssgeshmuuecdriiriduzuetdkynykacqlyzilpmfllfdgyhliwozeufydbklywrsfokxgdbhopukrguijughxkxogfolmcaudxcxeescfgabcaxumduflrhveicgkfdaophlalrtaxkxdriofndwwttyeunmochhibtuhpfnaxtmmtsumqsbnuhoknvvrfqolsaksaqfpxdombibnfsvyuhifayekztvoffcdzsyazflmfjbixbvmepwmudyahzhcpqyyzuyzcwosnznfuwfcblbtpgtzsunwyofdrzmofymxurdwzjuniqxthiavxschkgcxefaefqyjlvrzsvyxazxfgldlbxviylcwgebvkgblstpxzyotmfjdaysguvbxshkfijujvuxbzsdhwwsacrgjaufqyfdiaanllsnicwzkxijpvhwbdmlazituxlbucrmhzyksnwxcyatrcopmxcfcgqjpvglqayqwepegahyycrwpbbwaukazemkrsuloavslvkatjjqyfcwxgpikeyonxyqsiwuoahrghpcwwmvybgaonncehqqowyrumcwywlzttkogzguzcezqkcddazstseyhhqyjkebeuyyemmivhmykdkuruydrdgrhfcwwqjmefsrbuygbifvuktcccaafvniqdzmtrexmxcxzezqpkhtqpqjgdlvtcdgwfaelhitiahscbsqayziexemqiiijzchleekfdalwqcijlupldqamwozuatkjwbyvhwwrfvrqsirkizhfkizvtjtyixbrypodrhobkafwllypbrwchbpfuyufxtbjfapixaeaqxnepnpwybhqdhyygprowvnqwrjcnphbuqfxstwuxvywuemagwtujlacjgtriyluxcexjyttvhmrjkmpqohxnfxwmlktxgpakmgsvqxkjblqojbneovlzjqoxcefiwrqpeifgoxdhojzxszhdwfiggknbgdhlbezqglnistwuznojwvawnddwuwgwiejxmkuaepmcsbstygejuzojtdtqmijfvhfxydxxloowtyirjomtjpoobzxxhjskwjnvqofwzscnaxqhfouzimwywvimjwetnycttihkavywijbxfhfaihkkmyaxudbwdboalexekqyoysjuftwrsgfylazwqaigydkpwurnoekklcslzrslfcimosbgxoxzdeosdpvizornqygmfyteebjwpcxrwfudjiffymgiahrmfgvinntgtnbwhyhzjnsjvwwshzqnpnknjitienafvnwulzazpaoeubcsntohchmiqeunrdzyubelmxfnfsppcaqktboibpnqhzjktivwcfxvajjbgdyeabcqqwkfrtmbztayxhaclopmhccfaazkhrgixumhiglcjnucdyamzwykcqrvtlzxyemavvijaeztdqyuykavjdoawrztqfmibjhhetagnocbyoyplkmlwcwqezbgyhluhnwzvxflookbmlzyecstdwbubxkpnfhhimbkjzjvmcroaicbvvylbvihkoynpcntcxlnifyngaqfcsiqilcxjnnmibzfpwvjggzaysniuovokrllnuzlacjownthcxcfeypmttairpjfvhlyycidoymqfqhdvuxjedhfnziekdupaqqtnaaskssynplfthzxrklhmlaiqiposkvdzebevhufrskddkgxebikqcgbqmniwmiezbxwabvmcxgjifjfodswhfkdgtztvfwswlaghntjjdjwhqqjiowmvoomjkvximghjkzwksmaslucaaosodaipjoyuzunbqvklmkaemtjgezmakixjremydttiqbxgjklhpnrlpyghsvmymjuagtnjwbpqekwsjumjjrlchteyezhwurzzxneeljvagpmsbsmzrsvonnwprsvvxlqdqtwsrvrujctcbeidprubrjblaknjgpkmjeydsmzladtpvrjvegooirfaxpkogittojawoiqyldlyukdotlvthdmsewsrumnuzfkdqfquytwvhubjsfkfgoytjnzcpcwibhipphlblribtnqgtrzfdrrylyqiylkcmdszekzbwevzhhrslelbzjitdhngpxwakdvnzflugsdiopuejcjzpwmcdfiirvgthbcmbdvbveupybtmleywkosugjedkscqozicdbchdcwzrtexryzoxtvifihjlqsjxlhidgmvcwpvwgcqwdoeyqcsrtqzcrpkhdkjolouqcfaxhemygintpexlhpknhkvvaqveimhoybjjhzhmlpnvlckjbbcvsllzepjlytlwxdiwfpxkbhjabxoeeaoiigklvchwkpojhwgpslgnpmdomgvibndvyawlegmluyslswkdmjynwzjpxskbjjxntgxiblzrdqpkoujhgthmyulewzlcyodzdmoucjjbhfxuvrwktjkvedadpdeejuzdukiucklpfkwgjscndzefkjhzarezihprhhwqbsblljacukxkysyaqrogiozyycdodtfqiyvogvxdfdespjmvcysgoocqkuipvpdtpuhvynefiygtbycuknbpmrupnhhgoqsecivvpdcnagnzikjdladycquofusbystphrmsmqsbxodnidrcowolovftzzrhsienmnlqqfmxynknahogluxeubfspfvbygugigexaxqfnvvzitgcsuhrwyhtdezndoafsztredvgwxkngxgitudnmspkwougjkzkcrfkykzajrjudrllwmbqucvnkvrzayvqubrcqjqckbvuvndfndefbluizhaeexgvazbcybnsezekktmannynrnnruumswoacezjojedbyfhetnnderbsnjienxlvboksebbdqxmpkgqmfjfxbgcwsqfjjgfkffvaermerksrpaukjznyjcvixzhfydcoxleojespijcplugwghfpfovvcbebqdwxtdllcvkhseeodqunrcgrfhjmwdgahnxzsdsntpzdyoilcgdhtexyjylutcwwwfsnbttotxanoujtjrahsghuabchxgwxcgygjckaaipniumdoxitzollqsydxwvknmnntcoixapnvoibtimigntnkhscbliqrxmecwealszhgueiilhvkjfhojnqxqjvqfuslueuvnpretcpoarugqcbwxjrsuphwrpqfiyifqqglnodsklqkzfgbhuegkhydvgmqzpacnszappfrrgjvbmbofqasttolrayyqzcrtttrdlrevaigzacxnxqcnbfwadzemqtrzbfqspxzhixuopzgbadstyzvsvvdzrezflzqsztpbntyvwjxqmsjyxvysgljcljlssmkvvfdddnuaprvwckmsytuswgpyzdwugiaaazdswqnwwkjilmcuoaxwbxkjzzrgyktnnlxmotwscstbnatqwjxniwmmxuwcacnyqhxlebmaxyzgyimdleiizzzoemmgzqkldpjwapssincomsdmrnrdvfkasxowcnqiglwbhnsoafmilnraahhdinytvxifywnzkeijjyyrqszlyayroptawbtfltrwiptatybcpleliogjvakiimxiyaslcbrctauayvknjvmrwfnsygntfcjngmxjjewlgtpsnnnykxrlcsbwakctlcbjriamryryeoogsljfbifuwperegwhwzmioeenhumyaspgwkmamfiryvxrphhoyhtgysjpwrgluetawshwkdxwtotbswhnamtpjxpshfcidynfgujjdrfvsbfjtnbbhiguxztqrncnolvfpeugybdvmorcshvtktlryqcturaejkplklxagqcerdtskibgyzkqeeiegjqhbrhtuzxhgqfbrmvdvxysirslythfwvivsdlpswsicjfqmkatjmpbguvippmctkbfqydahrsjibvwtxlnviwtycrjyhttsadbrisliftdsfuxgtmepayfvvbojovkchjwvhkvxlwqbqfwbmdfgkpjlhpezktyldimbopulmophlojjuowcqcazdecplmwgouduzdsebmaywbwuyhghmihxnluzrljghanrutfrwsdsefvswhectmhvfanovgyzjatxxprfejxgzssqnzpwaamgqiatahweshqjhehkefakrksxtvplzmoxwqdpyydjpbpbitvtlhcfpvqmwvbunurzydqrvuhhhmxbpxlqarrakkaowyhtxqyvpewbalneiszceegrwraludumqlqgfdamyemjoyvvugwtarrowjppbpuepptvmmrmllaldtkesnonaaewdevlbnvczvlvnjmemxxsfdwdusvooqzamgjkqlpfdcatvjmaaupehrjbzhauqlyhkdkomltcrcxllagcbzjvtvrgqzodghxygtlinkbjlyhszvsrytgbmavvayfocokugpazjzjgnkaflunhztnswjpagjbkjlflydagnzsfhuuficmttrogefyxtqpkrptnlctquhyhpeuhtqguxmv"
print(logo_count(N, A))


# a 419
# 
# w 416
# 
# y 415

# In[5]:


N = 3
A = "szrmtbttyyaymadobvwniwmozojggfbtswdiocewnqsjrkimhovimghixqryqgzhgbakpncwupcadwvglmupbexijimonxdowqsjinqzytkooacwkchatuwpsoxwvgrrejkukcvyzbkfnzfvrthmtfvmbppkdebswfpspxnelhqnjlgntqzsprmhcnuomrvuyolvzlni"
print(logo_count(N, A))


# o 12
# 
# m 11
# 
# n 11

# In[6]:


N = 3
A = "tctesvgnclzykpmbcqixlonfidpdjbynrcpxsjmucpeyormenrjbibafpzkquminfnnbizgbpxeovefuykjrcebfnntvyamkgykcnvjqxvnprwrarpcgrjoucywgfnbnysgwzymcxyachlpsglosflsubqhvobedbtzuqmvgyvrpeclcsoeemysuyuejpjtahnrzmebztrjtzhhjtqlmhttxdnjilqsqymmhjmlzikkdzasshfktbfsaozyhaduyqcufucqxxuksnfjaiwacvlyiimfrzyxwobrfoalhmowcobbpwuqpwvlstbngxjrebfnckbcagoacmfuzvmqxefiwqkgfwgghxbulvhqiaqewdmmizjfgyymchohejdpsnnpvmtgqzxkesnrikywoolootuuikapycpxhkrplyuhzhndxckbvaynkzreybomwuemxtgmrjxbysarlsemwambppmrumivznuaqskzgpamfsjwwrjvtwyqpainuyyfmwnegjlmanqwvshvpsbpeykfwykdumdgjlkuwoxwqctihfdwvxrefggsxmjtxmpdcigjertcxwennzyamqpahytneybgmdyupusarhemazvozdqurftdvbnavynrsdzxjebjrdatbkoezdgwznplqqzakozjecyewsidawuxfpusmeusantzdglridxnwvbgwjcaofbplnwyxtmwerskdzwhgxfdqbpfhymlgwtvqeehnnhwgklxqkdjgmfxvuxwwpmnqxsaiitfehhbqdyveqfrqjjfnggmhjrgldgctnhzrrqdtbunxxcuwibqkjdickhrtbznevczqoidnfmtaveysysrgbhctwxmevuutrwyriugtuvhuxkqapfjyplczgekxisffoivofobqmipqxzunlrrtcmaivvhbfjvgywwtqubwszqwjtskyuxljhinqrhcgddejurivukcspaazjjwwloreqlreqjifwsv"
print(logo_count(N, A))


# m 47
# 
# n 46
# 
# w 46

# In[7]:


N = 3
A = "ybzhgdrefvdnjyfoswjuslbpuvtvfgzvnpayvjwzxkdpnbdnrsodnqhpqspojipjwgxaltzoikuucixfsoueknofvsohtqtvxvihtsevdojscucxwnivgzjazfsznswxbjylqejlgpkppwezlxhfhwuphrnqfdiowmeikwdozhjwmcneixidypdikthxxvppjakeffvhpmsxijiolpybpntbiuehpwkobetpglwxexuoxgwdbcsfvskkczxluccfkrwmpvbknadmbivdrypxtlmbnvqvcnoyciqcfnpkenvwkkosvsnxiqibkirlikwsdcnqruirprxhlenlrxahfiyhfgvbwqehddnqdtfgzwbyudmirkqmzkhxcwqxxvyrtrrmsezyvuanpcjisbfywzqesxyxlulaxamyedjyautncorctzanmosfpuescfqhrydrsohttsohvpkqppxdjsefcnelearcrypndesagvybsnzikxjqyzsvcpiypmkjaihrouvcajsxxsnsavasoxgigbhfxhbtivoyoflmmjmtxrxrsezgzcfkqiczphapeugunnyhpzpeisgohuuuchqcjbhvzojsaiecebllqevoakkfsdwqfuaozouhdgnuludvdcojalzztzkfmqxagdrlcekwyxerosaeplyzgjxwbiowidwgdnmdekjinuseaswpvmnpolistdinevfcfzlognzzfrlfoogxhyiwrfeaplrryyvyygxwgqbpaxcgrzfbhcsmbxeinwgmkpgzbdnoxdppkdvewajsnujyrojmiuvimgpkbhjmxsgaalyyovdipfeyiaeybyyvhdyacyuljzhmhtnvoapcijurxjbjalunfhtbvaiffutjxpvaedxyvrrqckxecqkniienwmmtkpwmpqkvhjigzqmtuouuxwmhohxyauzuakyvaekvyrjuuqgtcfptsuczdbeeloffdqewalyyygokdxor"
print(logo_count(N, A))


# p 49
# 
# x 49
# 
# i 47

# In[ ]:




