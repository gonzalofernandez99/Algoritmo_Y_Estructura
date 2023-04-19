<pre><div class="text_to_html">#include &lt;iostream&gt;
#include &lt;cstdlib&gt;
#include &lt;ctime&gt;
using namespace std;
#define TOPE 50000

void CargarVec(int CV_v[], int CV_t, int CV_m){
	int i;
	for(i=0; i&lt;CV_t;i++){
	//	cout&lt;&lt;&quot;vuelta: &quot;&lt;&lt;i&lt;&lt;&quot; Valor aleatorio: &quot;&lt;&lt;rand()%(CV_m)&lt;&lt;endl;
		CV_v[i]=rand()%(CV_m);
		//%(CV_m)	
	}
}

int main(){
	int vec[TOPE], mod=250;
	long long tini;
	srand(time(NULL));// Semilla 
	tini=clock();
	CargarVec(vec,TOPE, mod);
	cout&lt;&lt;&quot;Tiempo total de procesamiento usando la funcion clock(): &quot;&lt;&lt;clock()-tini&lt;&lt;endl;
	cout&lt;&lt;endl&lt;&lt;&quot;UNIDADES DE LA FUNCION CLOCK() POR SEGUNDO: &quot;&lt;&lt; CLOCKS_PER_SEC&lt;&lt;endl;
}






</div></pre>