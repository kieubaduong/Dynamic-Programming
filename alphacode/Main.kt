package alphacode

import java.util.Scanner

fun isSmallerThan26(a: Char, b: Char) : Boolean{
    return (a == '1' || a == '2' && b <= '6')
}

fun main(){
    var alphaCode : String
    val sc = Scanner(System.`in`)
    while (true){
        alphaCode = sc.nextLine()
        if(alphaCode== "0") break
        val dp = IntArray(alphaCode.length)
        dp[0] = 1
        if(alphaCode.length >= 2){
            if (isSmallerThan26(alphaCode[0], alphaCode[1]))
            {
                if (alphaCode[1] == '0')
                {
                    dp[1] = 1
                }
                else
                {
                    dp[1] = 2
                }
            }
            else
            {
                dp[1] = dp[0]
            }
        }
        for (i in 2 until alphaCode.length){
            if (isSmallerThan26(alphaCode[i - 1], alphaCode[i]))
            {
                if (alphaCode[i] == '0')
                {
                    dp[i] = dp[i - 2]
                }
                else if (alphaCode[i - 1] == '0')
                {
                    dp[i] = dp[i - 1]
                }
                else
                {
                    dp[i] = dp[i - 1] + dp[i - 2]
                }
            }
            else
            {
                dp[i] = dp[i - 1]
            }
        }
        println(dp[alphaCode.length - 1])
    }
}