//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlString.h
//    Author:      Streamlet
//    Create Time: 2009-03-27
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __XLSTRING_H_27999BE8_99C9_4C06_87AB_AA916A88B287_INCLUDED__
#define __XLSTRING_H_27999BE8_99C9_4C06_87AB_AA916A88B287_INCLUDED__


#include <xl/xlDef.h>
#include <xl/Containers/xlArray.h>

namespace xl
{
    template <typename T>
    class StringT
    {
    public:
        StringT();
        StringT(const T *szString);
        StringT(const StringT<T> &that);
        ~StringT();

    public:
        StringT<T> &operator = (const StringT<T> &that);
        bool operator == (const StringT<T> &that) const;
        bool operator != (const StringT<T> &that) const;
        bool operator < (const StringT<T> &that) const;
        bool operator > (const StringT<T> &that) const;
        bool operator <= (const StringT<T> &that) const;
        bool operator >= (const StringT<T> &that) const;
        StringT<T> operator + (const StringT<T> &that) const;
        StringT<T> &operator += (const StringT<T> &that);
        T &operator [] (int nIndex);
        const T &operator [] (int nIndex) const;

    public:
        const T *GetAddress() const;

    public:
        int Length() const;
        bool Empty() const;

    public:
        StringT<T> &MakeLower();
        StringT<T> &MakeUpper();
        StringT<T> ToLower() const;
        StringT<T> ToUpper() const;

    public:
        StringT<T> &AppendFront(T ch, int nCount = 1);
        StringT<T> &AppendBack(T ch, int nCount = 1);
        void Clear();

    public:
        StringT<T> Left(int nLength) const;
        StringT<T> Right(int nLength) const;
        StringT<T> SubString(int nStart, int nLength) const;

    public:
        int IndexOf(const StringT<T> &strFind, int nStart) const;
        int IndexOf(const StringT<T> &strFind) const;
        int LastIndexOf(const StringT<T> &strFind, int nStart) const;
        int LastIndexOf(const StringT<T> &strFind) const;

    public:
        StringT<T> Replace(const StringT<T> &strFind, const StringT<T> &strReplaceWith) const;
        Array<StringT<T>> Split(const StringT<T> &strSeparator) const;

    protected:
        Array<T> m_aData;
    };

    typedef char    CharA;
    typedef wchar_t CharW;
    typedef CharW   Char;

    typedef StringT<CharA> StringA;
    typedef StringT<CharW> StringW;
    typedef StringW        String;

    template <typename T>
    inline StringT<T>::StringT()
    {
        m_aData.PushBack(T(0));
    }

    template <typename T>
    StringT<T>::StringT(const T *szString)
    {
        if (szString != nullptr)
        {
            while (*szString != T(0))
            {
                m_aData.PushBack(*szString++);
            }
        }

        m_aData.PushBack(T(0));
    }

    template <typename T>
    inline StringT<T>::StringT(const StringT<T> &that)
    {
        *this = that;
    }

    template <typename T>
    inline StringT<T>::~StringT()
    {

    }

    template <typename T>
    inline StringT<T> &StringT<T>::operator = (const StringT<T> &that)
    {
        this->m_aData = that.m_aData;

        return *this;
    }

    template <typename T>
    inline bool StringT<T>::operator == (const StringT<T> &that) const
    {
        return this->m_aData == that.m_aData;
    }

    template <typename T>
    inline bool StringT<T>::operator != (const StringT<T> &that) const
    {
        return !(*this == that);
    }

    template <typename T>
    bool StringT<T>::operator < (const StringT<T> &that) const
    {
        for (size_t i = 0; i < this->m_aData.Size(); ++i)
        {
            if (this->m_aData[i] != that.m_aData[i] || this->m_aData[i] == T(0) || that.m_aData[i] == T(0))
            {
                return this->m_aData[i] < that.m_aData[i];
            }
        }

        return false;
    }

    template <typename T>
    bool StringT<T>::operator > (const StringT<T> &that) const
    {
        for (size_t i = 0; i < this->m_aData.Size(); ++i)
        {
            if (this->m_aData[i] != that.m_aData[i] || this->m_aData[i] == T(0) || that.m_aData[i] == T(0))
            {
                return this->m_aData[i] > that.m_aData[i];
            }
        }

        return false;
    }

    template <typename T>
    inline bool StringT<T>::operator <= (const StringT<T> &that) const
    {
        return !(*this > that);
    }

    template <typename T>
    inline bool StringT<T>::operator >= (const StringT<T> &that) const
    {
        return !(*this < that);
    }

    template <typename T>
    inline StringT<T> StringT<T>::operator + (const StringT<T> &that) const
    {
        StringT<T> strRet;

        strRet.m_aData.PopBack();
        strRet.m_aData.Insert(strRet.m_aData.End(), this->m_aData.Begin(), this->m_aData.End());
        strRet.m_aData.PopBack();
        strRet.m_aData.Insert(strRet.m_aData.End(), that.m_aData.Begin(), that.m_aData.End());

        return strRet;
    }

    template <typename T>
    inline StringT<T> &StringT<T>::operator+=(const StringT<T> &that)
    {
        this->m_aData.PopBack();
        this->m_aData.Insert(this->m_aData.End(), that.m_aData.Begin(), that.m_aData.End());

        return *this;
    }

    template <typename T>
    inline T &StringT<T>::operator[](int nIndex)
    {
        return m_aData[nIndex];
    }

    template <typename T>
    inline const T &StringT<T>::operator[](int nIndex) const
    {
        return m_aData[nIndex];
    }

    template <typename T>
    inline const T *StringT<T>::GetAddress() const
    {
        return &m_aData[0];
    }

    template <typename T>
    inline int StringT<T>::Length() const
    {
        return m_aData.Size() - 1;
    }

    template <typename T>
    inline bool StringT<T>::Empty() const
    {
        return Length() == 0;
    }

    template <typename T>
    StringT<T> &StringT<T>::MakeLower()
    {
        for (size_t i = 0; i < m_aData.Size(); ++i)
        {
            if (m_aData[i] >= T('A') && m_aData[i] <= T('Z'))
            {
                m_aData[i] += 'a' - 'A';
            }
        }

        return *this;
    }

    template <typename T>
    StringT<T> &StringT<T>::MakeUpper()
    {
        for (size_t i = 0; i < m_aData.Size(); ++i)
        {
            if (m_aData[i] >= T('a') && m_aData[i] <= T('z'))
            {
                m_aData[i] -= 'a' - 'A';
            }
        }

        return *this;
    }

    template <typename T>
    StringT<T> StringT<T>::ToLower() const
    {
        StringT<T> strRet;

        strRet.m_aData.Resize(this->m_aData.Size());

        for (size_t i = 0; i < m_aData.Size(); ++i)
        {
            if (this->m_aData[i] >= T('A') && this->m_aData[i] <= T('Z'))
            {
                strRet.m_aData[i] = m_aData[i] + ('a' - 'A');
            }
            else
            {
                strRet.m_aData[i] = m_aData[i];
            }
        }

        return strRet;
    }

    template <typename T>
    StringT<T> StringT<T>::ToUpper() const
    {
        StringT<T> strRet;

        strRet.m_aData.Resize(this->m_aData.Size());

        for (size_t i = 0; i < m_aData.Size(); ++i)
        {
            if (this->m_aData[i] >= T('a') && this->m_aData[i] <= T('z'))
            {
                strRet.m_aData[i] = m_aData[i] - ('a' - 'A');
            }
            else
            {
                strRet.m_aData[i] = m_aData[i];
            }
        }

        return strRet;
    }

    template <typename T>
    StringT<T> &StringT<T>::AppendFront(T ch, int nCount)
    {
        for (int i = 0; i < nCount; ++i)
        {
            m_aData.PushFront(ch);
        }

        return *this;
    }

    template <typename T>
    StringT<T> &StringT<T>::AppendBack(T ch, int nCount)
    {
        if (nCount <= 0)
        {
            return *this;
        }

        m_aData.PopBack();

        for (int i = 0; i < nCount; ++i)
        {
            m_aData.PushBack(ch);
        }

        m_aData.PushBack(T(0));

        return *this;
    }

    template <typename T>
    void StringT<T>::Clear()
    {
        m_aData.Clear();
        m_aData.PushBack(T(0));
    }

    template <typename T>
    inline StringT<T> StringT<T>::Left(int nLength) const
    {
        return SubString(0, nLength);
    }

    template <typename T>
    inline StringT<T> StringT<T>::Right(int nLength) const
    {
        return SubString(m_aData.Size() - 1 - nLength, nLength);
    }

    template <typename T>
    StringT<T> StringT<T>::SubString(int nStart, int nLength) const
    {
        StringT<T> strRet;

        if (nLength <= 0)
        {
            return strRet;
        }

        strRet.m_aData.PopBack();
        strRet.m_aData.Insert(strRet.m_aData.End(), m_aData.Begin() + nStart, m_aData.Begin() + nStart + nLength);

        if (strRet.m_aData[strRet.m_aData.Size() - 1] != T(0))
        {
            strRet.m_aData.PushBack(T(0));
        }

        return strRet;
    }

    template <typename T>
    inline int StringT<T>::IndexOf(const StringT<T> &strFind) const
    {
        return IndexOf(strFind, 0);
    }

    template <typename T>
    int StringT<T>::IndexOf(const StringT<T> &strFind, int nStart) const
    {
        if (strFind.Length() == 0)
        {
            return -1;
        }

        int i = nStart;

        while(i <= this->Length() - strFind.Length())
        {
            int j;

            for (j = 0; j < strFind.Length(); ++j)
            {
                if ((*this)[i + j] != strFind[j])
                {
                    if (i == this->Length() - strFind.Length())
                    {
                        return -1;
                    }

                    T ch = (*this)[i + strFind.Length()];

                    ++i;

                    for (int k = strFind.Length() - 1; strFind[k] != ch && k >= 0; --k)
                    {
                        ++i;
                    }

                    break;
                }
            }

            if (j >= strFind.Length())
            {
                return i;
            }
        }

        return -1;
    }

    template <typename T>
    inline int StringT<T>::LastIndexOf(const StringT<T> &strFind) const
    {
        return LastIndexOf(strFind, this->Length() - 1);
    }

    template <typename T>
    int StringT<T>::LastIndexOf(const StringT<T> &strFind, int nStart) const
    {
        if (strFind.Length() == 0)
        {
            return -1;
        }

        int i = nStart + 1 - strFind.Length();

        while(i >= 0)
        {
            int j;

            for (j = strFind.Length() - 1; j >= 0; --j)
            {
                if ((*this)[i + j] != strFind[j])
                {
                    if (i == 0)
                    {
                        return -1;
                    }

                    T ch = (*this)[i - 1];

                    --i;

                    for (int k = 0; strFind[k] != ch && k < strFind.Length(); ++k)
                    {
                        --i;
                    }

                    break;
                }
            }

            if (j < 0)
            {
                return i;
            }

        }

        return -1;
    }

    template <typename T>
    StringT<T> StringT<T>::Replace(const StringT<T> &strFind, const StringT<T> &strReplaceWith) const
    {
        StringT<T> strRet;

        int nFrom = 0;
        int nTo = this->IndexOf(strFind, nFrom);

        while (nTo != -1)
        {
            strRet += this->SubString(nFrom, nTo - nFrom);
            strRet += strReplaceWith;
            nFrom = nTo + strFind.Length();
            nTo = this->IndexOf(strFind, nFrom);
        }

        strRet += this->Right(this->Length() - nFrom);

        return strRet;
    }

    template <typename T>
    Array<StringT<T> > StringT<T>::Split(const StringT<T> &strSeparator) const
    {
        Array<StringT<T> > astrRet;

        int nFrom = 0;
        int nTo = this->IndexOf(strSeparator, nFrom);

        while (nTo != -1)
        {
            astrRet.PushBack(this->SubString(nFrom, nTo - nFrom));
            nFrom = nTo + strSeparator.Length();
            nTo = this->IndexOf(strSeparator, nFrom);
        }

        astrRet.PushBack(this->Right(this->Length() - nFrom));

        return astrRet;
    }

} // namespace xl

#endif // #ifndef __XLSTRING_H_27999BE8_99C9_4C06_87AB_AA916A88B287_INCLUDED__
