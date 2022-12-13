# Multix Zinnia Product SDK [Macro/Micro API core]

__Multix Zinnia Product SDK__
の共通サブモジュール。

AVR-GCC / AVR-LIBC 専用。__Arduino互換API用ではない。__

## 対象AVR

- megaAVR世代
  - megaAVR-0系統
  - tinyAVR-0/1/2系統
- modernAVR世代
  - AVR Dx系統
- reduceAVR世代
  - TPI対応系統

## パス配置

このモジュールは __Arduino IDE__ の
```boards.txt/platform.txt```において
以下のパスに配置される。

```plain
{runtime.platform.path}/cores/{build.core}        <-- このサブモジュール {includes}
{runtime.platform.path}/libraries/{build.core}    <-- MacroMicroAPI_lib
{runtime.platform.path}/libraries/M5_Modules      <-- M5_Modules_lib
{runtime.platform.path}/variants/{build.variant}  <-- ボード固有設定 {includes}
```

## 収容ライブラリ

|名称|機能|C|mega|modern|reduce|
|-|-|-|-|-|-|
|Arduino.h|API種別選択ヘッダ||✓|✓|✓
|_api/_|
|CLKCTRL_megaAVR.h|F_CPU初期化支援（megaAVR/tinyAVR）|✓|✓
|CLKCTRL_modernAVR.h|F_CPU初期化支援（modernAVR）|✓||✓
|CLKCTRL_reduceAVR.h|F_CPU初期化支援（reduceAVR）|✓|||✓
|HarfUART.h|半二重非同期UARTクラス||✓|✓
|Portmux.h|外部端子割付代替支援||✓|✓
|Print.h|Printクラス||✓|✓
|String.h|PGMEM補助クラス||✓|✓
|TWIM.h|二線式接続(I2C)主装置クラス||✓|✓
|UsartBaseClass.h|USART周辺機能支援クラス||✓|✓
|btools.h|基本データ処理支援|✓|✓|✓|✓
|capsule.h|カプセル変数共有体|✓|✓|✓|✓
|delay_busywait.h|遅延時間待機支援|✓|✓|✓|✓
|macro_api.h|MacroAPI|✓|✓|✓|✓
|macro_digital.h|外部端子操作マクロ|✓|✓|✓|\*
|power.h|CPU休止制御支援|✓|✓|✓|✓

> Cカテゴリは純粋C言語環境でも機能する。\
> reduceAVR の macro_digital 機能は variants パスに配置。

## 著作表示

Twitter: [@askn37](https://twitter.com/askn37) \
GitHub: [https://github.com/askn37/](https://github.com/askn37/) \
Product: [https://askn37.github.io/](https://askn37.github.io/)

Copyright (c) askn (K.Sato) multix.jp \
Released under the MIT license \
[https://opensource.org/licenses/mit-license.php](https://opensource.org/licenses/mit-license.php) \
[https://www.oshwa.org/](https://www.oshwa.org/)
