#include <bits/stdc++.h>
using namespace std;

class Accounting {
    //privateには外部からアクセスできない（非公開）
private:
    //データメンバ
    string full_name; //氏名
    long crnt_asset; //資産
//メンバ関数(name,asset,earn,spend)厳密にはコンストラクタもそうらしい（？）
public:
    //コンストラクタ（初期化）
    Accounting(string name, long asset) {
        //dataメンバの名前を変更→メンバ関数と同名は許されない
        full_name = name; // 氏名
        crnt_asset = asset; // 資産
    }
    // 氏名（データメンバ）を調べて返却
    string name() {
        return full_name;
    }
    //資産（データメンバ）をしらべて返却　　
    long asset() {
        return crnt_asset;
    }
    //このようなデータメンバの値を'取得'するようなメンバ関数name,assetのことをゲッタ(getter)
    //逆にデータメンバに特定の値を'設置'するメンバ関数をセッタと呼ぶ（setter）
    //総称してアクセッサとよぶ

    //収入
    void earn(long yen) {
        crnt_asset += yen;
    }
    //支出
    void spend(long yen) {
        crnt_asset -= yen;
    }

};
//クラスって;いるんやね！！
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