#include <iostream>
using namespace std;

//DO NOT EDIT code below this line

class Book {
  public:
    Book(string t, string a, string g) {
      title = t;
      author = a;
      genre = g;
    }

    string GetTitle() {
      return title;
    }

    void SetTitle(string new_title) {
      title = new_title;
    }

    string GetAuthor() {
      return author;
    }

    void SetAuthor(string new_author) {
      author = new_author;
    }

    string GetGenre() {
      return genre;
    }
  
    void SetGenre(string new_genre) {
      genre = new_genre;
    }
  
  private: 
    string title;
    string author;
    string genre;
};

//DO NOT EDIT code above this line

//add class definitions below this line

//DO NOT EDIT////////////////////
class BlogPost : public Book { //
/////////////////////////////////
  public:
    BlogPost(string t, string a, string g, string w, int wc, int pv) : Book(t, a, g) {
      website = w;
      word_count = wc;
      page_views = pv; 
    }
  
    string GetWebsite() {
      return website;
    }
  
    void SetWebsite(string new_website) {
      website = new_website;
    }
  
    int GetWordCount() {
      return word_count;
    }
  
    void SetWordCount(int new_word_count) {
      word_count = new_word_count;
    }
  
    int GetPageViews() {
      return page_views;
    }
  
    void SetPageViews(int new_page_views) {
      page_views = new_page_views;
    }
  
  private:
    string website;
    int word_count;
    int page_views;
};  

  
//add class definitions above this line

int main() {
  
  //DO NOT EDIT code below this line

  BlogPost my_post("Hot Summer Trends", "Amy Gutierrez", "fashion", "Vogue", 2319, 2748);
  cout << my_post.GetTitle() << endl;
  cout << my_post.GetAuthor() << endl;
  cout << my_post.GetGenre() << endl;
  cout << my_post.GetWebsite() << endl;
  cout << my_post.GetWordCount() << endl;
  cout << my_post.GetPageViews() << endl;
  BlogPost codio("Adopting Codio", "Anh Le", "computer science", "Codio", 2500, 5678);
  cout << codio.GetTitle() << endl;
  cout << codio.GetAuthor() << endl;
  cout << codio.GetGenre() << endl;
  cout << codio.GetWebsite() << endl;
  cout << codio.GetWordCount() << endl;
  cout << codio.GetPageViews() << endl;

  //DO NOT EDIT code above this line
  
  return 0;
  
}
