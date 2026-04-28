#pragma once
#include "BulletEffect.h"
#include <vector>

#define BulletEffectNUM 20

class C_EffectManager {
public:
    //最大数分だけエフェクトを初期化
    void Init(KdTexture* tex) {
        for (int i = 0; i < 100; i++) {
            m_effects[i].Init();
            m_effects[i].SetTex(tex);
        }
    }

    //更新処理（寿命が残っているものだけ動かす）
    void Update() {
        for (int i = 0; i < 100; i++) {
            if (m_effects[i].GetLifespan() > 0) {
                // BulletEffect側のUpdateを呼び出す
                // 引数は現状の設計に合わせて渡しますが、内部で座標更新されます
                m_effects[i].Update({ 0,0 }, false);
            }
        }
    }

    //描画処理
    void Draw() {
        for (int i = 0; i < 100; i++) {
            if (m_effects[i].GetLifespan() > 0) {
                m_effects[i].Draw();
            }
        }
    }

    //関数呼び出しだけでエフェクトを出すための関数
    void Add(Math::Vector2 pos, Math::Vector2 move, float size, Math::Color color, int life) {
        for (int i = 0; i < 100; i++) {
            if (m_effects[i].GetLifespan() <= 0) {
                m_effects[i].Emit(pos, move, size, color, life, false); //
                break;
            }
        }
    }

private:
    C_BulletEffect m_effects[100]; //エフェクトが入る箱の数
};