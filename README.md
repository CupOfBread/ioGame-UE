## ioGame_UE

ioGame 与 Unreal Engine 综合示例联调

综合示例(文档)：https://www.yuque.com/iohao/game/ruaqza#YbA30

## 说明
Build.cs中加入"Protobuf", "WebSockets"

Websocket初始化在`WebsocketGameInstance`内编写，设置`编辑->项目设置->项目->地图和模式->游戏实例类`设置为`WebsocketGameInstance`

进入UE后选择`io_GameMode`，将`io_Actor`拖入地图场景，调用`io_Actor`的`LoginCommand`函数即可

`Source\ThirdParty\Protobuf\lib`内生成`pb.h`、`pb.cc`文件

## 版本

|          | 版本   |
| -------- | ------ |
| UE       | 5.0.3  |
| Protobuf | 3.21.9 |

## 链接

ioGame(文档)：https://www.yuque.com/iohao/game

ioGame(后端仓库)：https://github.com/iohao/iogame

UE集成WebSocket：https://www.youtube.com/watch?v=l9TTmtDBTWY&t=463s