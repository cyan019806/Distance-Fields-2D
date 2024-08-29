Distance Fields(距離場):

定義: 由空間中任一點到模型的最短距離形成的場

![image](https://github.com/user-attachments/assets/7adc3f4c-c759-4385-ae8e-592f2756746d)

用途: 佈置管線、擷取特定層面

步驟:

1. 創建 2D 網格
   
2. 輸入模型:
   
   (1) 點
   
      ![image](https://github.com/user-attachments/assets/c26aa8f1-c8d4-4733-9b42-613b81cca2d9)
   
   (2) 直線
   
      ![image](https://github.com/user-attachments/assets/957cc538-3ed5-48b4-a1a5-8904ad64f550)
   
   (3) V字形
   
      ![image](https://github.com/user-attachments/assets/fc93408f-f44a-4060-9ec6-9ebede3707fa)
   
3. 將空間的體素分為三類:

   (1) DONE: 距離場已決定，距離值不會再改變
   
   (2) CLOSE: 緊鄰 DONE 的體素，距離值可能還會隨著計算變小
   
   (3) FAR: 善未計算距離值的體素
   
5. 計算距離場
   
   (1) 偏微分方程:
   
      ![image](https://github.com/user-attachments/assets/4e2c60ab-a9a7-4119-9a57-62ad721c18ef)
   
   f: 距離場傳播速度，設為1, 1/f: 時間
   
      ![image](https://github.com/user-attachments/assets/67ff91e7-2baf-468b-a565-07d9028cbcaa) : 距離場增長最快的方向
   
   (2) 不確定係數法(Undetermined Coefficient Method): 用來近似偏微分方程為二次多項式
   
   假設體素V(𝑖, 𝑗, 𝑘)的距離場為 𝑢(𝑖, 𝑗, 𝑘)，位置 xyz 的偏微分可以寫成:
   
      ![image](https://github.com/user-attachments/assets/b5d9f029-6153-4828-ab5c-d76ca28d8a88)

   其中 𝐴𝑥  𝐵𝑥  𝐶𝑥, 𝐴𝑦  𝐵𝑦  𝐶𝑦, 𝐴𝑧  𝐵𝑧  𝐶𝑧 為要求的係數
   
   根據體素種類會產生五種情形(以 x 方向為例):
   
     ![image](https://github.com/user-attachments/assets/ec8d1af8-482e-4a5c-ac17-d5df2fb0d829)
     ![image](https://github.com/user-attachments/assets/7c90ee0f-ae04-4e0d-8b49-03f9a5349160)
  
  (3) 將求得的係數代入微分方程:
  
      ![image](https://github.com/user-attachments/assets/204ed66e-8ab4-486a-9d4e-48525a5d7551)
   
   經過整理二次多項式的係數 𝑎_𝑥, 𝑎_𝑦, 𝑎_𝑧:
   
   ![image](https://github.com/user-attachments/assets/c4f31c77-7792-4f13-96ec-9b41e029d1f8)
   
  (4) 用公式解求根，取較大的根為距離值
  
5. 流程:

   (1) 每次疊代從 CLOSE 中移除距離值最小的體素 target 加入 DONE 集合中 (將 CLOSE 排序後 target 為第一個 node)
   
   (2) target 體素的鄰居在 CLOSE 或 FAR 中距離值可能會被更新:
   
       如果在 FAR 集合: 從 FAR 集合中移除，加入 CLOSE 集合
   
       如果在 CLOSE 集合: 調整在 CLOSE 集合中的位置
   
   (3) 重複上述步驟直到 CLOSE 集合變為空集合
   
6. 結果
   
  (1) 點模型
  
   ![iso-curve_point](https://github.com/user-attachments/assets/f6ea3dfb-c105-4259-a656-34688e7f8544)
   
  (2) 直線模型
  
   ![iso-curve_line](https://github.com/user-attachments/assets/cfb05c86-3605-48ea-b88c-60bbcb831f3b)
  
  (3) V字形模型
  
   ![iso-curve_v](https://github.com/user-attachments/assets/e433c9cb-2ff3-43a7-8f8b-3196ce151378)
