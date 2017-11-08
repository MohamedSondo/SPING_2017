int main(int argc, char* argv[])
{
/*
float a[N], b[N], x = 0.0;
for (i = 0; i < N; i++)
x = x + a[i]*b[i];
*/
const int N = 8;
static float a[N]={1.0,2.0,1.0,2.0,1.0,2.0,1.0,2.0},
 b[N]={2.0,1.0,2.0,1.0,2.0,1.0,2.0,1.0},
 x = 0.0;
float *aPointer = a;
float *bPointer = b;
__asm
{
pxor xmm0, xmm0
;initialize xmm0 to 0 , xmm0 will serve as x
mov eax, dword ptr[aPointer] ;eax points to a[]
mov ebx, dword ptr[bPointer] ;ebx points to b[]
mov ecx, N
;number of elements in arrays

myLOOP:
movups xmm1, [eax] ;four values of a in xmm1
movups xmm2, [ebx] ;four values of b in xmm2
mulps xmm1, xmm2 ;mulitply a[i]*b[i]
addps xmm0, xmm1 ;add x + a[i]*b[i]

add eax, 16 ;increment pa by 4
add ebx, 16 ;increment pb by 4
sub ecx, 4 ;loop-4
jnz myLOOP ;loop if ecx not 0
haddps xmm0, xmm0 ;horizontal add
haddps xmm0, xmm0 ;horizontal add
movss dword ptr[x], xmm0 ;result goes to x
 }
return 0;
}