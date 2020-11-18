# team_cub3D
This is the repository of Cub3D project by the team of rnakai and kkamashi

# チーム
rnakai kkamashi

# 目標
BHの2020年12月21日（土）16:42までにこのプロジェクトを絶対にクリアさせて、次のレベルに進むこと

# 第一回提出日（目標）
12月9日（土）：BH期限より12日前（余裕を持って3回はリトライできる）

# チーム開発方法
開発の流れは、以下のサイトを参考。<br>
https://qiita.com/siida36/items/880d92559af9bd245c34

- 主たるブランチはmain
- 開発はmainからfeatureブランチを切って開発
- featureブランチ名は作業内容を分かりやすくしよう。（例：kkamashi/func_to_read_texture, rnakai/func_to_set_texture etc）
- こまめにcommit、タスクが終わったらpush
- 少なくとも１日１プッシュ
- 新しいタスクに取り組む時には、必ず一度mainに戻ってからブランチを切り直そう（git checkout main）
- 始める前にgit pull origin mainでアップデート。

# 全体でのTODOリスト

# 終わっているパート
## rnakai

## kkamashi
1. cub3dファイルの読み込み箇所
2. cub3dファイルのそれぞれの要素を構造体にパース
3. cub3dファイルのエラーチェック
4. cub3dファイルのマップデータの有効チェック
5. キーコマンドによるアクション

# 残りのパート

1. Rayのキャスティング -> DONE
2. textureの読み込み -> NOW by rnakai
3. sprite
4. BMPファイルへの出力 -> NOW by kkamashi
5. normチェック
6. 最終的なエラーチェック

## rnakaiのパート
1. 描画のところを引き続きやる -> DONE
2. textureの貼り付け -> NOW

## kkamashiのパート
1. マップデータを長方形に整形 -> DONE
2. convert rbg to hex
3. bmpファイルを作る関数
4. textureを貼る勉強
5. cubファイル読み込みのエラーパターンをどんどん追加して精度を高める