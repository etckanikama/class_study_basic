#include <bits/stdc++.h>
using namespace std;

//クラス定義の中で単一のソースを管理するのは難しい
// コンストラクタを含め、メンバ関数の定義はクラス定義の外にも置ける
//earnとspendの関数定義をクラスの外に移動したプログラム
//クラス定義外にメンバ関数を定義するときもクラス定義内に宣言だけはしなくてはならない！！！

// コンストラクタを含めクラスの外で定義するメンバ関数の名前は以下の通り
// クラス名:: メンバ関数名　

// クラス名::をつけるのはそのメンバ関数の名前がクラス有効範囲(class scope)の中にあることを示すため


class Accounting {
    //privateには外部からアクセスできない（非公開）
private:
    //データメンバ
    string full_name; //氏名
    long crnt_asset; //資産
//メンバ関数(name,asset,earn,spend)厳密にはコンストラクタもそうらしい（？）
public:
    Accounting(string name, long amnt);  // コンストラクタ ＜宣言＞
    string name() {return full_name;} // 氏名を調べる　→ゲッタ
    long asset() { return crnt_asset;} //資産を調べる　→ゲッタ

    void earn(long amnt); // 預ける　→　＜宣言＞
    void spend(long amnt); // おろす　→　＜宣言＞
};
// ＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿

// --- コンストラクタ ----
Accounting::Accounting(string name, long amnt) // 定義＜宣言したものを＞
{
    full_name = name;   //氏名
    crnt_asset = amnt; // 資産
}

void Accounting::earn(long amnt) // 定義＜宣言したものを＞
{
    crnt_asset += amnt; 
}

void Accounting::spend(long amnt) // 定義＜宣言したものを＞
{
    crnt_asset -= amnt; 
}



int main() {
    //　コンストラクタの呼び出し（クラス名　変数（引数））= 初期化？
    Accounting kanikama("かにかま", 1000); //かにかま君の会計
    Accounting hirayama("ひらやま", 200); //平山君の会計
    //メンバ関数の呼び出し
    kanikama.spend(200); // かにかま君が200円の支出
    hirayama.earn(100); // 平山君が100円の収入

    cout << "かにかま\n" << kanikama.name() << kanikama.asset() << "円\n";
    cout << "ひらやま\n" << hirayama.name() << hirayama.asset() << "円\n";

}