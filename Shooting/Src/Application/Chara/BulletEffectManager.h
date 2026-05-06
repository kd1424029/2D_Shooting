#pragma once
#include "BulletEffect.h"
#include <vector>

#define BulletEffectNUM 20 //エフェクトが発生したときの数

static const int EffectMax = 200; //エフェクト自体の数

class C_EffectManager {
public:

    void SetTex(KdTexture* tex)
    {
        for (int i = 0; i < EffectMax; ++i)
        {
            m_effects[i].SetTex(tex);
        }
    }

    //最大数分だけエフェクトを初期化
    void Init()
    {
        m_nextFree = 0;

        for (int i = 0; i < EffectMax; ++i)
        {
            m_effects[i].Init();
        }
    }

    //更新処理（寿命が残っているものだけ動かす）
    void Update() 
    {
        for (int i = 0; i < EffectMax; ++i) {
            if (m_effects[i].GetLifespan() > 0) 
            {
                //BulletEffect側のUpdateを呼び出す
                m_effects[i].Update({ 0,0 }, false);
            }
        }
    }

    //描画処理
    void Draw() 
    {
        for (int i = 0; i < EffectMax; ++i)
        {
            if (m_effects[i].GetLifespan() > 0) 
            {
                m_effects[i].Draw();
            }
        }
    }

    void Add(Math::Vector2 pos, Math::Vector2 move, float size, Math::Color color, int life)
    {
        //前回の空きから探し始める（毎回0から探さない）
        for (int i = 0; i < EffectMax; ++i)
        {
            int idx = (m_nextFree + i) % EffectMax;

            if (m_effects[idx].GetLifespan() <= 0)
            {
                m_effects[idx].Emit(pos, move, size, color, life, false);
                m_nextFree = (idx + 1) % EffectMax; // 次の空き候補を記録
                break;
            }
        }
    }

private:
    C_BulletEffect m_effects[EffectMax];
    int m_nextFree = 0; 
};